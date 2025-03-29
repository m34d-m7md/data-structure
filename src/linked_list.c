#include <stdio.h>
#include <stdlib.h>
#include "../inc/linked_list.h"

typedef struct Node node_t;
struct Node {
  double value;
  node_t *next;
};

typedef struct LinkedList linked_list_t;

static node_t *create_node(double value) {
  node_t *node = (node_t *) malloc(sizeof(node_t));
  node->value = value;
  node->next = NULL;
  return node;
}

static int add(linked_list_t *self, size_t index, double value) {
  if (index > self->len) return 0;

  node_t *node = create_node(value);
  int len = self->len++;

  if (index == 0) {
    node->next = self->head;
    self->head = node;

    return 1;
  }

  node_t *curr = self->head;

  for (int i = 0; i < index - 1; i++) curr = curr->next;

  if (index ==  len) {
    curr->next = node;
    return 1;
  }

  node->next = curr->next;
  curr->next = node;

  return 1;
}

static double drop(linked_list_t *self, size_t index) {
  if (index > self->len) return 0.0;

  node_t *temp;
  double value;
  self->len--;

  if (index == 0) {
    temp = self->head;
    value = temp->value;
    self->head = self->head->next;
    free(temp);

    return value;
  }

  node_t *curr = self->head;

  for (int i = 0; i < index - 1; i++) curr = curr->next;

  temp = curr->next;
  value = temp->value;
  curr->next = curr->next->next;
  free(temp);

  return value;
}

static double get(linked_list_t *self, size_t index) {
  if (index >= self->len) return 0.0;

  node_t *curr = self->head;

  for (int i = 0; i < index; i++) curr = curr->next;

  return curr->value;
}

static void print(linked_list_t *self) {
  for (int i = 0; i < self->len; i++) {
    printf("# %.1lf ", get(self, i));
  }

  printf("#");
}

linked_list_t create_linked_list() {
  linked_list_t *list = (linked_list_t *) malloc(sizeof(linked_list_t));
  list->head = NULL;
  list->len = 0;
  list->add = add;
  list->drop = drop;
  list->get = get;
  list->print = print;
  return *list;
}
