newton-method: newton-method.o
	g++ newton-method.o -o main -lmpfr -lgmp -std=gnu++11

newton-method.o: newton-method.cpp
	g++ -c newton-method.cpp -std=gnu++11 -O3

clean:
	rm -f *.o 