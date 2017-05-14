all:
	gcc sequential.c -o sequential -g -lm 
	gcc data_parallel.c -o data_parallel -g -lm -pthread

