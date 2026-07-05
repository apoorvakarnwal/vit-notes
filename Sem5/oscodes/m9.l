%{
#include <stdio.h>
#include <string.h>

int max_length = 0;  // Store the length of the longest word
%}

%%

[a-zA-Z]+   { 
                int length = strlen(yytext);
                if (length > max_length) {
                    max_length = length;
                }
            }

[^a-zA-Z]+   { /* Ignore non-word characters */ }

%%
int yywrap(){
	return 1;
}
int main() {
    printf("Enter a string: ");
    yylex();
    printf("Length of the longest word: %d\n", max_length);
    return 0;
}

