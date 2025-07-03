#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
#define MAX 100

List* init_history(){
  List* history = malloc(sizeof(List));
  if(!history){
    return NULL;
  }
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str){
  if(!list || !str){
    return;
  }
  Item* newItem = malloc(sizeof(Item));
  if(!newItem){
    return;
  }
  newItem->str = copy_str(str, MAX);
  if(!newItem->str){
    free(newItem);
    return;
  }
  newItem->next = NULL;
  if(!list->root){
    newItem->id = 0;
    list->root = newItem;
  }
  else{
    Item* current_node = list->root;
    while(current_node->next){
      current_node = current_node->next;
    }
    newItem->id = current_node->id +1;
    current_node->next = newItem;
  }
}

char *get_history(List *list, int id){
  if(!list || id < 0){
    return NULL;
  }
  Item* current_node = list->root;
  while(current_node){
    if(current_node->id == id){
      return current_node->str;
    }
    current_node = current_node->next;
  }
  return NULL;
}

void print_history(List *list){
  if(!list || !list->root){
    return;
  }
  Item* current_node = list->root;
  while(current_node){
    printf("%d\n", current_node->id);
    printf("%s\n", current_node->str);
    current_node = current_node->next;
  }
}

void free_history(List *list){
  if(!list){
    return;
  }
  Item* current_node = list->root;
  while(current_node){
    Item* next_node = current_node->next;
    free(current_node->str);
    free(current_node);
    current_node = next_node;
  }
  free(list);
}
