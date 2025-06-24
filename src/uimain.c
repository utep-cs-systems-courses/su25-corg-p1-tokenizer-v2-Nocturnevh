#include <stdio.h>


/* Simple user interface for Section A Lab 1 */
int main(){
  char str[100];
  printf("$ ");
  fgets(str, sizeof(str), stdin);
  printf("%s\n", str);
}
