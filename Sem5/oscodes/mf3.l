%{
#include <stdio.h>

int vowels = 0;     // Counter for vowels
int consonants = 0; // Counter for consonants
%}

%%

[aeiouAEIOU]   { vowels++; }

[a-zA-Z]       { consonants++; }

[^a-zA-Z]      { /* Ignore non-alphabetic characters */ }

%%

int main() {
    printf("Enter a string: ");
    yylex();
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    return 0;
}
int yywrap(){
	return 1;
}
