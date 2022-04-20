#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
int yylex();
void yyerror(const char *msg, ...);
int yyparse();

extern char *readfile_name;

#endif // _MAIN_H

