%{
#include <stdio.h>
%}

%%

abb { printf("Matched string with 'abb': %s\n", yytext); }

.   { printf("Matched string without 'abb': %s\n", yytext); }

%%
int yywrap() {
return 1;
}
int main() {
    yylex();
    return 0;
}

