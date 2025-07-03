#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAX 100

/* Simple user interface for Section A Lab 1 */
int main(){
  char str[MAX];
  printf("Welcome to my tokenizer, type a string and watch it be tokenized. To exit type !q.\n");
  
  while(1){
    printf("$ ");
    
    if(fgets(str, sizeof(str), stdin) == NULL){
      printf("\n Exiting... \n");
      break;
    }
    /* Echos back user input. */
    printf("%s\n", str);
    
    /* Handle exiting from program using !q*/
    if(str[0] == '!' && str[1] == 'q'){
      printf("Goodbye.\n");
      break;
    }

    char **tokens = tokenize(str);
    print_tokens(tokens);
    free_tokens(tokens);
  }
  return 0;
}
