#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Definição dos tipos de token
typedef enum {
    ENDFILE, ERROR, NUM
} TokenType;

//estado atual do AFD
extern int current_state;

extern FILE* source; /*arquivo de texto*/


#endif