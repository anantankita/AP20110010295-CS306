%{
  #include<stdio.h>
%}

%%
[0|1]*00  {printf("String Accepted!");}
[0|1]*[01|10|11]    {printf("String Rejected!");}
stop {return 0;}
%%
yywrap(){};
int main()
{
  printf("Enter the string: ");
  yylex();
  return 0;
}