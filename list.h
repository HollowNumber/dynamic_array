#pragma once

typedef struct {
  int *data;
  int capacity;
} List;

List createList(int initial_capacity);

/**
 * places the given element at the end of the list
 */
void put(List *list, int data);

/**
 * Pops the last element
 */
void pop(List *list);

/**
 * Removes the value at the given index and swaps it with the value at the last
 * index
 */
void swapback(List *list, int index);

/*
 * Adds to the list whilst preserving order.
 */
void addToList(List *list, int index, int data);

void removeFromList(List *list, int index);

void printList(List *list);
