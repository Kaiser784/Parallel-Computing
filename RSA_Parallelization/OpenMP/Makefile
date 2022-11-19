serial_gprof:
	g++ -fopenmp -pg -g -O0 rsa_serial.cpp && ./a.out
	gprof -b a.out > gprof.out
	cat gprof.out

serial_gcov:
	g++ --coverage -fopenmp -fprofile-arcs -ftest-coverage -O rsa_serial.cpp -lgcov && ./a.out
	mv a-rsa_serial.gcno rsa_serial.gcno
	mv a-rsa_serial.gcda rsa_serial.gcda
	gcov rsa_serial.cpp
	cat rsa_serial.cpp.gcov

likwid:
	likwid-perfctr -c 0-4 -g FLOPS_DP ./a.out

run:
	g++ -fopenmp pollardSerial.cpp && ./a.out

runp:
	export OMP_NUM_THREADS=2
	g++ -fopenmp pollardOpenMP.cpp && ./a.out

clean:
	rm *.gcov a.out	*.gcno *.gcda

