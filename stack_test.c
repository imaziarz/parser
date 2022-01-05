#include "fun_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
	int i, t;
	char* str = "test";
	stack_t stack = malloc(sizeof(stack_t));
        stack->top = -1;
        stack->capacity = 2;
        stack->nums = (int*)malloc(sizeof(int) * stack->capacity);
        stack->names = (char**)malloc(sizeof(char*) * stack->capacity);
	
	if (argc == 1){
		srand(time(NULL));
		t = rand()%4;
	}
	else
		t = atoi(argv[1]);
	
	switch (t){
		case 0: 
			printf("test: przepelnienie stosu\n");
			for (i=0; i<1025; i++)
				put_on_fun_stack (i, str, stack);
			for (i=0; i<1025; i++){
				printf("para: %d", top_of_fun_stack( stack ));
				printf(", %s\n", get_from_fun_stack( stack ));
			}
			break;
		case 1:
			printf("test: maksymalne zapelnienie stosu\n");
			for (i=0; i<1024; i++)
                                put_on_fun_stack (i, str, stack);
                        for (i=0; i<1024; i++){
                                printf("para: %d", top_of_fun_stack( stack ));
                                printf(", %s\n", get_from_fun_stack( stack ));
                        }
			break;
		case 2:
			printf("test: zabranie elementu ze stosu pustego\n");
			printf("element: %s\n", get_from_fun_stack( stack ));
			break;
		case 3:
			printf("test: liczba w pustym stosie\n");
			printf("liczba: %d\n", top_of_fun_stack( stack ));
			break;
		default:
			printf("test: dodanie 3 elementow do stosu, zabranie elementu, wyswietlenie liczby, dodanie 1 elementu, wyswietlenie 2 elementow: liczba, napis\n");
			for (i=0; i<3; i++)
				put_on_fun_stack (i, str, stack);
			printf("%s\n", get_from_fun_stack( stack ));
			printf("%d\n", top_of_fun_stack( stack ));
			put_on_fun_stack (i, str, stack);
			for (i=0; i<2; i++)
				printf("%d, %s\n", top_of_fun_stack( stack ), get_from_fun_stack( stack ));
			break;
	}
	return 0;
}
