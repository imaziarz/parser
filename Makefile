CC = cc
test: stack_test.o fun_stack.o
	$(CC) -o test stack_test.o fun_stack.o
fun_stack.o: fun_stack.c fun_stack.h
	$(CC) -o fun_stack.o -c fun_stack.c
stack_test.o: stack_test.c fun_stack.h
	$(CC) -o stack_test.o -c stack_test.c
parser.o: parser.c fun_stack.h
	$(CC) -o parser.o -c parser.c
alex.o: alex.c alex.h fun_stack.h
	$(CC) -o alex.o -c alex.c
parser: 
	$(CC) -o parser parser.o alex.o fun_stack.o
