all: program0 program1 program2 program3
	./program0

program0: program0.c
	gcc -pthread -lrt program0.c -o program0

program1: program1.c
	gcc -pthread -lrt program1.c -o program1

program2: program2.c
	gcc -pthread -lrt program2.c -o program2

program3: program3.c
	gcc -pthread -lrt program3.c -o program3

clean:
	rm program0 program1 program2 program3
	clear
	ls