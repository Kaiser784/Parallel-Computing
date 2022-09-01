serial_gprof:
	g++ -fopenmp -pg -g -O0 rsa_serial1.cpp && ./a.out
	gprof -b a.out > gprof.out
	cat gprof.out

serial_gcov:
	g++ --coverage -fopenmp -fprofile-arcs -ftest-coverage -O rsa_serial1.cpp -lgcov && ./a.out
	mv a-rsa_serial1.gcno rsa_serial1.gcno
	mv a-rsa_serial1.gcda rsa_serial1.gcda
	gcov rsa_serial1.cpp
	cat rsa_serial1.cpp.gcov

likwid:
	likwid-perfctr -c 0-4 -g FLOPS_DP ./a.out

run:
	g++ -fopenmp rsa_serial1.cpp && ./a.out

clean:
	rm *.gcov a.out	*.gcno *.gcda

