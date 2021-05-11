main: main.o
	cc -o main main.o -lstdc++ -lm -ffast-math

main.o:
	cc -c main.cc

clean:
	rm main main.o