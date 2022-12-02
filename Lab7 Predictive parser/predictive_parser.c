//C program for the computation of FIRST and FOLLOW for a given CFG
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int n, i, j, m, p;
char f[10];
char arr[10][10];
void follow(char c);
void first(char c);

int main(){
  int i,z;
  char c,ch;
  printf("Enter no of production rule: ");
  scanf("%d", &n);
  printf("\nEnter production rules: ");
  for(i=0;i<n;i++)
  scanf("%s%c",arr[i],&ch);
  do{
    m=0;
    printf("\nEnter an element:");
    scanf("%c", &c);
    first(c);
    printf("\nFirst(%c) : { ",c);
    for(i=0; i<m; i++){
      printf("%c",f[i]);
    }
    printf(" }\n");
    strcpy(f," ");
    m=0;
    follow(c);
    printf("Follow(%c) : { ",c);
    for(i=0; i<m; i++){
      printf("%c",f[i]);
    }
    printf(" }\n");
    printf("\nDo you want to continue finding FIRST and FOLLOW(0/1): ");
    scanf("%d%c",&z,&ch);
  }while(z == 1);
  return(0);
}

void first(char c){
  int k;
  if(!isupper(c))
    f[m++] = c;
  for(k=0;k<n;k++){
    if(arr[k][0] == c){
      if(arr[k][2] == '$'){
        follow(arr[k][0]);
      }
      else if(islower(arr[k][2])){
        f[m++] = arr[k][2];
      }
      else{
        first(arr[k][2]);
      }
    }
  }
}

void follow(char c){
  if(arr[0][0] == c)
    f[m++] = '$';
  for(i=0;i<n;i++){
    for(j=2; j<strlen(arr[i]); j++){
      if(arr[i][j] == c){
        if(arr[i][j+1] !='\0'){
          first(arr[i][j+1]);
        }
        if(arr[i][j+1] == '\0' && c!= arr[i][0]){
          follow(arr[i][0]);
        }
      }
    }
  }
}
