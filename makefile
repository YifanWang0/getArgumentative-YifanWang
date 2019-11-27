all: getArg_main.o
	gcc -o program getArg_main.o

getArg_main.o: getArg_main.c
	gcc -c getArg_main.c

run:
	./program

clean:
	rm *.o
	rm *~

memcheck:
	valgrind --leak-check:yes ./program
