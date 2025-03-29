#ifndef SORT
#define SORT

#include <stdio.h>
#include <stdlib.h>

typedef struct Sort sort_t;
struct Sort {
  void (*merge)(double arr[], int len);
  void (*bubble)(double arr[], int len);
  void (*print)(double arr[], int len);
};

sort_t create_sort();

#endif
