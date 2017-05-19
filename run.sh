#!/bin/bash

#Executions for 100 size vector------------------------------

#Sequential
for i in `seq 1 10`;
do
    { time ./sequential.exe 100; } 2>> ./output/sequential/sequencial-100.txt
done 

#2 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 100 2; } 2>> ./output/control/control-100-2threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 100 2; } 2>> ./output/data/data-100-2threads.txt
done 

#4 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 100 4; } 2>> ./output/control/control-100-4threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 100 4; } 2>> ./output/data/data-100-4threads.txt
done 

#6 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 100 6; } 2>> ./output/control/control-100-6threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 100 6; } 2>> ./output/data/data-100-6threads.txt
done 

#8 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 100 8; } 2>> ./output/control/control-100-8threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 100 8; } 2>> ./output/data/data-100-8threads.txt
done 


#Executions for 10.000 size vector------------------------------

#Sequential
for i in `seq 1 10`;
do
    { time ./sequential.exe 10000; } 2>> ./output/sequential/sequencial-10000.txt
done 

#2 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 10000 2; } 2>> ./output/control/control-10000-2threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 10000 2; } 2>> ./output/data/data-10000-2threads.txt
done 

#4 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 10000 4; } 2>> ./output/control/control-10000-4threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 10000 4; } 2>> ./output/data/data-10000-4threads.txt
done 

#6 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 10000 6; } 2>> ./output/control/control-10000-6threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 10000 6; } 2>> ./output/data/data-10000-6threads.txt
done 

#8 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 10000 8; } 2>> ./output/control/control-10000-8threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 10000 8; } 2>> ./output/data/data-10000-8threads.txt
done 


#Executions for 1.000.000.000 size vector------------------------------

#Sequential
for i in `seq 1 10`;
do
    { time ./sequential.exe 1000000000; } 2>> ./output/sequential/sequencial-1000000000.txt
done 

#2 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 1000000000 2; } 2>> ./output/control/control-1000000000-2threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 1000000000 2; } 2>> ./output/data/data-1000000000-2threads.txt
done 

#4 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 1000000000 4; } 2>> ./output/control/control-1000000000-4threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 1000000000 4; } 2>> ./output/data/data-1000000000-4threads.txt
done 

#6 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 1000000000 6; } 2>> ./output/control/control-1000000000-6threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 1000000000 6; } 2>> ./output/data/data-1000000000-6threads.txt
done

#8 threads-----------------------------

#Control
for i in `seq 1 10`;
do
    { time ./control.exe 1000000000 8; } 2>> ./output/control/control-1000000000-8threads.txt
done 

#Data
for i in `seq 1 10`;
do
    { time ./data.exe 1000000000 8; } 2>> ./output/data/data-1000000000-8threads.txt
done