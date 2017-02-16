CC = gcc
DEBUG = gdb
FLAGS = -lm -ggdb

test: test-cmp
	${PWD}/test

test-debug: test-cmp
	${DEBUG} ${PWD}/test

test-cmp: obj 
	${CC} ${FLAGS} test.o -o test

obj: clean
	${CC} ${FLAGS} -c src/test.c

clean:
	rm -rf *.o
