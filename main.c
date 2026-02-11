#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  List list = createList(0);

  for (int i = 0; i < 10; i++) {
    addToList(&list, i);
  }

  printList(&list);

  removeFromList(&list, 0);
  printf("\n\n");

  printList(&list);

  free(list.data);
  return 0;
}
