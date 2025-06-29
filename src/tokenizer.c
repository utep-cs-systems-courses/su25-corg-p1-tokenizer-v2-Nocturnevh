#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c){
  if(c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(space_char(c) != 1){
    return 1;
  }
  return 0;
}

char *token_start(char *str){
  while(*str != '\0'){
    if(non_space_char(*str)){
      return str;
    }
    str++;
  }
}

char *token_terminator(char *token){
  while(*token != '\0'){
    token++;
  }
  return token;
}

int count_tokens(char *str){

}
