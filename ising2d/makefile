ising-2d: ising-2d.o
	g++ -o ising-2d ising-2d.o  -lmtwister -lmpfr -std=gnu++11 -lgfortran -lm

ising-2d.o: ising-2d.cpp
	g++ -c ising-2d.cpp -std=gnu++11 -O3

clean:
	rm -f *.o 