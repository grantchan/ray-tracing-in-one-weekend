main: main.o
	cc -o main main.o -lstdc++

main.o:
	cc -c main.cc

clean:
	rm main main.o