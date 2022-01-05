#include "alex.h"
#include <string.h>
#include <ctype.h>

static int  ln= 0;
static char ident[256];
static FILE *ci= NULL;

void    alex_init4file( FILE *in ) {
   ln= 0;
   ci= in;
}

int isKeyword (char* word){
	char keyword[23][10]={"double","int","struct","break","else","long","switch","case","enum","typedef","char","return","const","float","continue","for","void","default","sizeof","do","if","static","while"};
	for (int i=0; i<23; i++) 
		if (strcmp(word, keyword[i]) == 0) return 1;
	return 0;
}

lexem_t alex_nextLexem( ) {
  int c;
  while( (c= fgetc(ci)) != EOF ) {
    if( isspace( c ) )
                        continue;
                else if( c == '\n' )
                        ln++;
    else if( c == '(' )
                        return OPEPAR;
    else if( c == ')' )
      return CLOPAR;
    else if( c == '{' )
                        return OPEBRA;
    else if( c == '}' )
                        return CLOBRA;
    else if( isalpha( c ) ) {
      int i= 1;
      ident[0] = c;
      while( isalnum( c= fgetc(ci) ) )
                                ident[i++] = c;
      ident[i] = '\0';
      return isKeyword(ident) ? OTHER : IDENT;
                } 
     else if( c == '"' ) {
     	int cp = c;
	while( (c= fgetc(ci)) != EOF && c != '"' )
        	cp = c;
	return c==EOF ? EOFILE : OTHER; 
    } 
    else if( c == '/' )
      return OTHER;
        }       
  return EOFILE;
}

char *  alex_ident( void ) {
   return ident;
}

int     alex_getLN() {
        return ln;
}

