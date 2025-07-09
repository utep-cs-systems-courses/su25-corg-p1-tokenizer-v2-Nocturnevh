#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 100

/* Simple user interface for Section A Lab 1 */
int main(){
  char str[MAX];
  List *history = init_history();

  
  printf("Welcome to my tokenizer, type a string and watch it be tokenized.\n");
  printf("To view history !h.\nTo view num history  type ! followed by number 0-9.\n");
  
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
    /*Handle history display using !h*/
    if(str[0] == '!' && str[1] == 'h'){
      printf("History:\n");
      print_history(history);

    }

    else if(str[0] == '!' && str[1] >= '0' && str[1] <= '9'){
      int id = str[1] - '0';
      char *recalled_str = get_history(history, id);
      if(recalled_str){
	printf("Recalling: %s\n", recalled_str);
	char **tokens = tokenize(recalled_str);
	print_tokens(tokens);
	free_tokens(tokens);
      }
      else{
	printf("No history item found with id %d\n", id);
      }
    }
    else{
      int i = 0;
      while(str[i] != '\0'){
	if(str[i] == '\n'){
	  str[i] = '\0';
	  break;
	}
	i++;
      }
    

    add_history(history, str);

    char **tokens = tokenize(str);
    print_tokens(tokens);
    free_tokens(tokens);
    }
  }
  free_history(history);
  return 0;
}
