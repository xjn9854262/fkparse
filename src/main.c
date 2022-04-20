#include "main.h"
#include "ast.h"
#include <stdarg.h>

void yyerror(const char *msg, ...) {
  va_list ap;
  va_start(ap, msg);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, msg, ap);
  fprintf(stderr, "\n");
}

char *readfile_name;

static char *getFileName(char *path) {
  char *retVal = path, *p;
  for (p = path; *p; p++) {
    if (*p == '/' || *p == '\\' || *p == ':') {
      retVal = p + 1;
    }
  }
  retVal[strlen(retVal) - 4] = 0;
  return retVal;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    yyin = fopen(argv[1], "r");
    if (!yyin) {
      fprintf(stderr, "cannot open file %s\n", argv[1]);
      exit(-1);
    }
  } else {
    printf("usage: %s <filename>\n", argv[0]);
    exit(0);
  }

  char filename[0xFFF];
  readfile_name = getFileName(argv[1]);
  sprintf(filename, "%s.lua%c", readfile_name, 0);

  yyout = fopen(filename, "w+");
  yyparse();
}
