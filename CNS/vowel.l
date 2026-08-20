%{
#include <stdio.h>
%}

%%

^[aeiouAEIOU]    { printf("First alphabet is a VOWEL\n"); }
^[a-zA-Z]        { printf("First alphabet is NOT a vowel\n"); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}