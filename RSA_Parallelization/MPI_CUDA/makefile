PROGS =  pollardMpi
OBJECT1 = pollardSerial.o
# OBJECT2 = pollardCuda.o
LDFLAGS = -lm 
CC = g++
NCC =nvcc
MCC=mpicc

all: $(PROGS) 

pollardMpi: 
	$(MCC) -fopenmp pollardMpi.c -o pollardMpi.out -lm

mpinon: 
	$(MCC) -fopenmp pollardMpi.c -o pollardMpi.out -lm
	mpirun -np 4 ./pollardMpi.out

clean: 
	rm -f $(PROGS) *.o  *.out

mpirun:
	mpirun -f hosts ./pollardMpi.out
