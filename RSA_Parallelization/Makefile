serial_gprof:
	g++ -fopenmp -pg -g -O0 rsa_serial1.cpp -lm && ./a.out
	gprof -b a.out > gprof.out
	cat gprof.out

serial_gcov:
	g++ -fopenmp -fprofile-arcs -ftest-coverage -O2 rsa_serial1.cpp -lgcov && ./a.out
	gcov rsa_serial1.cpp
	cat rsa_serial1.cpp.gcov

run:
	g++ -fopenmp -pg -g -O0 rsa_serial1.cpp && ./a.out

build_parallel:
	g++ -pg -g -O0 rsa_parallel.cpp && ./a.out
	gprof -l a.out > gprof.out
	cat gprof.out

clean:
	rm a.out gmon.out gprof.out