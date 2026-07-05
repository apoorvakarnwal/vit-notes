%{
#include <stdio.h>
#include <stdlib.h>
int valid_date_found = 0;
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
    valid_date_found = 1;}

.|\n {
    // Ignore invalid characters or newlines in this section
}
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the string: ");
    yylex();

    if (valid_date_found==0) {
        printf("\nInvalid Date\n");
    }

    return 0;
}

