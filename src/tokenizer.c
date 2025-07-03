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
  return NULL;
}

char *token_terminator(char *token){
  while(*token != '\0'){
    token++;
  }
  return token;
}

int count_tokens(char *str){
  int count = 0;
  char *pos = str;

  while((pos = token_start(pos)) != NULL){
    count++;
    while(*pos != '\0' && !space_char(*pos)){
      pos++;
    }
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *newStr = malloc((len+1) * sizeof(char));
  for(int i = 0; i < len; i++){
    newStr[i] = inStr[i];
  }
  newStr[len] = '\0';
  return newStr;
}

char **tokenize(char* str){
  int count =  count_tokens(str);
  char **token = malloc((count +1) * sizeof(char *));
  char *pos = str;
  int i = 0;

  while(i < count){
    pos = token_start(pos);
    char *start = pos;
    int len =  0;

    while(*pos != '\0' && !space_char(*pos)){
      len++;
      pos++;
    }
    token[i] = copy_str(start, len);
    i++;
  }
  token[count] = NULL;
  return token;
}

void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    printf("Tokens[%d] = %s\n", i, tokens[i]);
    i++;
  }
  printf("Tokens[%d] = %d\n", i, 0);
}

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
