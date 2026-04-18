#ifndef _SCAN_H
#define _SCAN_H

#include "globals.h"

//Tamanho maximo de um lexema
#define MAXTOKENLEN 40

//O lexema atual que fica disponivel globalmente
extern char tokenString[MAXTOKENLEN + 1];

//Função que implemenda o AFD do analisador léxico
TokenType getToken(void);

//Aplica a verificação a frente
int getNextChar(void);
//Aplica o retrocesso
void ungetNextChar(void);

#endif