// E -> TE’
// E’ -> +TE’ | ͼ
// T -> FT’
// T’ -> *FT’ | ͼ
// F -> (E) | i

#include<stdio.h>
#include<string.h>

void E(), Edash(), T(), Tdash(), F();
char str[100];
int i=0;

void E() {
    T();
    Edash();
}

void Edash() {
    if(str[i]=='+') {
        i++;
        T();
        Edash();
    }
}

void T() {
    F();
    Tdash();
}

void Tdash() {
    if(str[i]=='*') {
        i++;
        F();
        Tdash();
    }
}

void F() {
  if(str[i]=='i') {
    i++;
  } 
  else if(str[i]=='(') {
    i++;
    E();
    if(str[i]==')') {
      i++;
    } 
  
  else {
    return;
    }
  }
}

int main(){
	printf("Enter a string: ");
  scanf("%s",str);
  E();
  int l=strlen(str);
  if(i==l) {
      printf("String accepted!");
  } 
  else {
      printf("String not accepted!");
  }
}
