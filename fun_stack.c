#include "fun_stack.h"
#include <stdio.h>
#include <stdlib.h>
#define maxsize 1024

int top_of_fun_stack ( funstack_t stack ){
	return stack->nums[stack->top];
}


void put_on_fun_stack (int par_level, char* funame, funstack_t stack){
	if (stack->top == stack->capacity-1){
		if (stack->capacity == maxsize){
			fprintf(stderr, "Stack overflow\n");
			exit(1);
		}
		stack->capacity *= 2;
		stack->nums = realloc(stack->nums, sizeof(int) * stack->capacity);
		if (stack->nums == NULL){
			fprintf(stderr, "Blad podczas alokowania pamieci do tablicy liczb\n");
			exit(1);
		}
		stack->names = realloc(stack->names, sizeof(char*) * stack->capacity);
		if (stack->names == NULL){
			fprintf(stderr, "Blad podczas alokowania pamieci do tablicy napisow\n");
			exit(1);
		}
	}
	stack->top++;
	stack->nums[stack->top] = par_level;
	stack->names[stack->top] = funame;
}

char* get_from_fun_stack ( funstack_t stack ){
	if (stack->top == -1){
		fprintf(stderr, "Stack underflow\n");
		exit(1);
	}
	char* funame = stack->names[stack->top];
	stack->top--;
	return funame;
}



