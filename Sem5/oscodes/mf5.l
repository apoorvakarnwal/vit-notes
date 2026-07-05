%{
#include <stdio.h>
%}

%%

abb        { printf("Matched string with 'abb': %s\n", yytext); }
[^a]*abb[^a]*  { /* This pattern will match any string containing 'abb' */}
[a-zA-Z0-9]+   { printf("Matched string without 'abb': %s\n", yytext); }
.            { /* Any other characters not matching valid strings */ }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}

