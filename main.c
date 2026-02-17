#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  List list = createList(0);

  for (int i = 0; i < 10; i++) {
    put(&list, i);
  }

  printList(&list);

  printf("swapback:\n");
  swapback(&list, 2);

  printList(&list);
  printf("pop:\n");
  pop(&list);

  printList(&list);

  printf("addToList:\n");
  addToList(&list, 1, 200);

  printList(&list);

  printf("removeFromList:\n");
  removeFromList(&list, 4);

  printList(&list);

  free(list.data);

  return 0;
}
