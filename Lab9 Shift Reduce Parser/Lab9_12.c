#include<stdio.h>
#include<stdlib.h>

void pop(),push(char ),display();
int top=-1;
char *ip;
char stack[100]="\0";
char inputbuffer[100];


int main(){
  printf("The given grammar is\n\n");
  printf("S->0S0\n");
  printf("S->1S1\n");
  printf("S->2\n");
  printf("Enter input string followed by $: ");
  scanf("%s",inputbuffer);
  ip=inputbuffer;
  push('$');
  printf("STACK\t BUFFER \t ACTION\n");
  printf("-----\t ------- \t ------\n");
  display();
  do
  {
  if((stack[top]=='S' && stack[top-1]=='$') && (*(ip)=='$'))
  break;
  if(stack[top]=='$'){
    push(*ip);
    ip++;
    printf("Shift");
  }
  else if(stack[top]=='2'){
    display();
    pop();
    push('S');
    printf("Reduce S->2\n");
  }
  else if(stack[top]=='0' && stack[top-1]=='S' && stack[top-2]=='0'){
    display();
    pop();
    pop();
    pop();
    push('S');
    printf("Reduce S->0S0");
  }
  else if(stack[top]=='1' && stack[top-1]=='S' && stack[top-2]=='1'){
    display();
    pop();
    pop();
    pop();
    push('S');
    printf("Reduce S->1S1");
  }
  else {
    display();
    push(*ip);
    ip++;
    printf("shift");
  }
  }while(1);
  display();
  printf(" Accept\n\n\n");
  }
  void push(char c)
  {
    top++;
    stack[top]=c;
  }
  void pop()
  {
    stack[top]='\0';
    top--;
  }
  void display()
  {
  printf("\n%s\t%s\t",stack,ip);
}
