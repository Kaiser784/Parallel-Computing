build_serial:
	g++ -pg -g -O0 rsa_serial.cpp 
	gprof -l a.out > gprof.out
	cat gprof.out

build_parallel:
	g++ -pg -g -O0 rsa_parallel.cpp 
	gprof -l a.out > gprof.out
	cat gprof.out

clean:
	rm a.out gmon.out gprof.out