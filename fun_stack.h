#ifndef _FUN_STACK_H_IS_INCLUDED_
#define _FUN_STACK_H_IS_INCLUDED_
#include <stdlib.h>
typedef struct Stack{
        int top;
        int capacity;
        int* nums;
        char** names;
}*stack_t;

int top_of_fun_stack( stack_t stack );  // zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
void put_on_fun_stack( int par_level, char *funame, stack_t stack ); // odkłada na stos parę (funame,par_level)
char *get_from_fun_stack( stack_t stack ); // usuwa z wierzchołka parę (funame,par_level), zwraca zdjętą funame

#endif

