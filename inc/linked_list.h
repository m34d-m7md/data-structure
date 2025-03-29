#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct Node node_t;

typedef struct LinkedList linked_list_t;
struct LinkedList {
  node_t *head;
  size_t len;
  int (*add)(linked_list_t *self, size_t index, double value);
  double (*drop)(linked_list_t *self, size_t index);
  double (*get)(linked_list_t *self, size_t index);
  void (*print)(linked_list_t *self);
};

linked_list_t create_linked_list();

#endif
