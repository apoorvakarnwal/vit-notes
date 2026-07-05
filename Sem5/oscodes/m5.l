%{
#include <stdio.h>
#include <stdlib.h>
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
    return;
}

.|\n {
}

%%

int yywrap() {
    return 1;
}

int main() {
    char input[100];
    printf("Enter the string: ");
    fgets(input, sizeof(input), stdin);

    YY_INPUT(input, 0, sizeof(input));

    int result = yylex();

    if (result == 0) {
        printf("\nInvalid Date: %s\n", input);
    }

    return 0;
}

