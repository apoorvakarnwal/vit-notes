%{
#include <stdio.h>
#include <stdlib.h>
int valid_date_found = 0; // Flag to track if a valid date has been found
%}
D [0-9]
y {D}{D}{D}{D}            // Match a 4-digit year
m 0[1-9]|1[0-2]            // Match month between 01-12
d 0[1-9]|[12][0-9]|3[01]   // Match day between 01-31
s /                        // Match the '/' separator
n \n                       // Match newline character

date {d}{s}{m}{s}{y}|{y}{s}{m}{s}{d}  

%%

{date} {
    printf("\nValid Date: %s\n", yytext);
    valid_date_found = 1;}

%%

int yywrap() {
    return 1;  // End of input
}

int main() {
    printf("Enter the string: ");
    yylex();  // Run lexer

    // Print "Invalid Date" only if no valid date is found
    if (!valid_date_found) {
        printf("\nInvalid Date\n");
    }

    return 0;
}

