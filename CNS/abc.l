%{
#include <stdio.h>
%}

%%

\n      { printf("Sponge Bob\n"); }

.       ;
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}