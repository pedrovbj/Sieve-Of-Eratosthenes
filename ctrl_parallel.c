#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct info_pos {
    int prime;
    int pos;
    int end;
} info_pos_t;

typedef struct info {
    int num_threads;
    int max_num;
    int count;
    info_pos_t cur_pos;
} info_t;

typedef struct control {
    pthread_mutex_t next_mutex;
} control_t;

int *number;
info_t data;
control_t control;

void *check_prime(void *arg);
void get_next(info_pos_t *info);

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Wrong usage. You should type:\n\t./control <target_number> <number_of_threads>\n");
        return 0;
    }

    data.num_threads = atoi(argv[2]);
    data.max_num = atoi(argv[1]);
    data.cur_pos.prime = 2;
    data.cur_pos.pos = 0;
    data.cur_pos.end = data.max_num/data.num_threads;
    data.count = 1;

    pthread_mutex_init(&control.next_mutex, NULL);
    number = (int *) calloc(data.max_num-1, sizeof(int));

    long i;
    void *res;
    pthread_t thread[data.num_threads];
    
    for(i = 0; i < data.num_threads; i++) {
        pthread_create(&thread[i], NULL, check_prime, (void *) i);
    }

    for(i = 0; i < data.num_threads; i++) {
        pthread_join(thread[i], &res);
    }

    // int j = 0;
    // for(i = 0; i < data.max_num-1; i++) {
    //     if(!number[i]) {
    //         printf("%ld\t", i+2);
    //         j++;
    //     }
    // }
    // printf ("\n%d\n", j);

    pthread_mutex_destroy(&control.next_mutex);
    // free(number);
    pthread_exit(NULL);
    return 0;
}

void *check_prime(void *arg) {
    int i;
    info_pos_t info;

    info.pos = 0;
    while(1) {
        pthread_mutex_lock(&control.next_mutex);
            get_next(&info);
        pthread_mutex_unlock(&control.next_mutex);

        if(info.pos < 0) {
            break;
        }

        for(i = (info.pos/info.prime)*info.prime + ((info.pos % info.prime > 0)? info.prime : 0); i <= info.end; i += info.prime) {
            if(i > info.prime) {
                number[i-2] = 1;
            }
        }
    }
    pthread_exit(NULL);
}

void get_next(info_pos_t *info) {
    int i;

    *info = data.cur_pos;
    
    if(data.cur_pos.end >= data.max_num) {
        for(i = 0; i < data.max_num-1; i++) {
            if(!number[i] && (i+2 > data.cur_pos.prime)) {
                data.cur_pos.prime = i+2;
                data.cur_pos.pos = 0;
                data.count = 1;
                data.cur_pos.end = data.max_num/data.num_threads;
                break;
            }
        }
        if(i == data.max_num-1) {
            data.cur_pos.pos = -1;
        }
    } else {
        data.count++;
        data.cur_pos.pos = data.cur_pos.end+1;
        data.cur_pos.end = (data.count * data.max_num/data.num_threads);
    }
}