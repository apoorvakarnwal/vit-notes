%{
#include <stdio.h>
%}

%%
([0-2][0-9]|3[01])   "/"   (0[1-9]|1[0-2])   "/"   [0-9]{4}  { printf("Valid date: %s\n", yytext); }
.|\n                   { printf("Invalid date: %s\n", yytext); }
%%

int main() {
    yylex();  // Start the lexical analysis
    return 0;
}

