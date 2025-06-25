#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c){
  if(c = '\t' | c = ' '){
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
  int i = 0;
  while(str[i] != '\0'){
    if(non_space_char(str[i])){
      return &str[i];
    }
    i++;
  }
  return "\0";
}

char *token_terminator(char *token){
  int i =0;
  while(non_space_char(word[i])){
    i++;
  }
  if(word[i] == '\0'){
    return "\0";
  }
  i--;
  return &word[i];
}
