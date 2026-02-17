
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List createList(int initial_capacity) {

  List list;
  int *data;

  int size = sizeof(*data) * initial_capacity;

  data = malloc(size);

  if (data == NULL)
    return list;

  list.data = data;

  list.capacity = initial_capacity;

  return list;
}

void put(List *list, int data) {
  int *tmp_data;

  list->capacity++;

  // Realloc current size + size of new data

  int new_size = list->capacity * sizeof(int);

  tmp_data = realloc(list->data, new_size);

  if (tmp_data == NULL)
    return;

  tmp_data[list->capacity - 1] = data;

  list->data = tmp_data;
}

void pop(List *list) {
  int *tmp_data;

  int cap = list->capacity - 1;

  int new_size = cap * sizeof(int);

  tmp_data = realloc(list->data, new_size);

  if (tmp_data == NULL)
    return;

  list->capacity = cap;
  list->data = tmp_data;
}

// Swapback
void swapback(List *list, int index) {
  int *tmp_data;
  int last_value = list->data[list->capacity - 1];

  int cap = list->capacity - 1;

  int new_size = cap * sizeof(int);

  tmp_data = realloc(list->data, new_size);

  if (tmp_data == NULL)
    return;

  tmp_data[index] = last_value;

  list->capacity = cap;
  list->data = tmp_data;
}

void addToList(List *list, int index, int data) {
  int *tmp_data;

  list->capacity = list->capacity + 1;

  int new_size = list->capacity * sizeof(int);

  tmp_data = realloc(list->data, new_size);

  if (tmp_data == NULL)
    return;

  // naive - loop and move indices from input index to new capacity

  for (int i = list->capacity - 1; i < index; i--) {
    tmp_data[i] = tmp_data[i - 2];
  }

  tmp_data[index] = data;

  list->data = tmp_data;
}

void removeFromList(List *list, int index) {
  int *tmp_data;
  int last_value = list->data[list->capacity - 1];

  int cap = list->capacity - 1;

  int new_size = cap * sizeof(int);

  tmp_data = realloc(list->data, new_size);

  if (tmp_data == NULL)
    return;

  for (int i = index; i < cap; i++) {
    tmp_data[i] = tmp_data[i + 1];
  }

  tmp_data[cap - 1] = last_value;

  list->capacity = cap;
  list->data = tmp_data;
}

void printList(List *list) {

  int length = list->capacity;

  for (int i = 0; i < length; i++) {
    printf("Index: %d - value: %d\n", i, list->data[i]);
  }
  printf("\n");
}
