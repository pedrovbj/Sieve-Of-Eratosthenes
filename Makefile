all:
	gcc sequential.c -o sequential.exe -g -lm 
	gcc data_parallel.c -o data.exe -g -lm -pthread
	gcc ctrl_parallel.c -o control.exe -g3 -lm -pthread
