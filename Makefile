all:
	gcc sequential.c -o sequential.exe -g -lm 
	gcc data_parallel.c -o data_parallel.exe -g -lm -pthread
	gcc ctrl_parallel.c -o ctrl_parallel.exe -g3 -pthread
