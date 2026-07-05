%{
#include <stdio.h>
#include <stdlib.h>

int valid_date_found = 0; // Flag to track if a valid date has been found

%}

D [0-9]
y {D}{D}{D}{D}
m 0[1-9]|1[0-2]
d 0[1-9]|[12][0-9]|3[01]
s /
n \n

date {d}{s}{m}{s}{y}|{y}{s}{m}{s}{d}

%%

{date} {
    printf("\nValid Date: %s\n", yytext);
    valid_date_found = 1; // Mark valid date as found
}

. {
    // Ignore invalid characters or newlines in this section
}

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();  // Run lexer
    if (!valid_date_found) {
        printf("\nInvalid Date\n");
    }
    return 0;
}

