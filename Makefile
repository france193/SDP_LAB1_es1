target:
	clear
	gcc -g -o main -Wall main.c

clean:
	rm main

run:
	./main 20 100