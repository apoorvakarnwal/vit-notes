%{
#include<stdio.h>
#include<stdlib.h>
%}

D [0-9]
y {D}{D}{D}{D}
m [0][1-9]|[1][012]
d [0][1-9]|[12][0-9]|[3][01]
s [/]
n [\n]
In [.][\n]
date {d}{s}{m}{s}{y}|{y}{s}{m}{s}{d}

%%

{date} {printf("\nValid Date: %s\n", yytext);}
In   {printf("\nInValid Date: %s\n", yytext);}

%%
int yywrap(){
	return 1;
}
int main(){
	printf("Enter the string: ");
	yylex();
	return 0;
}
