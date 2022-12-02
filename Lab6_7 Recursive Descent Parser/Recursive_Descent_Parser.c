// S  -> (L)
// S  -> a
// L  -> SL'
// L' -> ,SL'
// L' -> ͼ

#include<stdio.h>
#include<string.h>

void S(), L(), Ldash();
char str[100];
int i=0;

void S(){
  if(str[i]=='('){
    i++;
    L();
    if(str[i]==')'){
      i++;
    }
  } 
  else if(str[i]=='a'){
      i++;
  }
}

void L(){
  S();
  Ldash();
}

void Ldash(){
  if(str[i]==','){
    i++;
    S();
    Ldash();
  }
  return;
}

int main(){
	printf("Enter a string: ");
  scanf("%s",str);
  S();
  int l=strlen(str);
  if(i==l){
    printf("String accepted!");
  } 
  else{
    printf("String not accepted!");
  }
}