PROGS =  pollardMpi
OBJECT1 = pollardSerial.o
# OBJECT2 = pollardCuda.o
LDFLAGS = -lm 
CC = g++
NCC =nvcc
MCC=mpicc

all: $(PROGS) 

pollardMpi: pollardMpi.c
	$(MCC) -fopenmp pollardMpi.c -o pollardMpi.out -lm

clean: 
	rm -f $(PROGS) *.o  *.out

mpirun:
	mpirun -f hosts ./pollardMpi.out
