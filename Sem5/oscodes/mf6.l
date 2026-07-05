%{
#include <stdio.h>
%}

%%

abb         { printf("Matched string with 'abb': %s\n", yytext); }
[^a]*abb[^a]* { printf("Matched string containing 'abb': %s\n", yytext); }
[a-zA-Z0-9]+ { printf("Matched string without 'abb': %s\n", yytext); }
.           { printf("Matched a non-alphanumeric character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a string to analyze:\n");
    yylex();
    return 0;
}

