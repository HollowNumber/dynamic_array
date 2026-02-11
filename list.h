#pragma once

typedef struct {
  int *data;
  int capacity;
} List;

List *createList(int initial_capacity);

void addToList(List *list, int data);

void removeFromList(List *list, int index);

void printList(List *list);
