#include <stdio.h>
#include <stdlib.h>
#include "../inc/sort.h"

typedef struct Sort sort_t;

static void merge(double arr[], int len) { // O(nlog(n))
  if (len <= 1) return;

  int left_len = len / 2;
  int right_len = len - left_len;
  double *left = (double *) malloc(sizeof(double) * left_len);
  double *right = (double *) malloc(sizeof(double) * right_len);

  for (int i = 0; i < left_len; i++) left[i] = arr[i];
  for (int i = 0; i < right_len; i++) right[i] = arr[left_len + i];

  merge(left, left_len);
  merge(right, right_len);

  int i = 0, j = 0, k = 0;

  while (j < left_len && k < right_len) {
    if (left[j] < right[k]) {
      arr[i++] = left[j++];
    } else {
      arr[i++] = right[k++];
    }
  }
  
  while (j < left_len) arr[i++] = left[j++];
  while (k < right_len) arr[i++] = right[k++];

  free(left);
  free(right);
}

static void bubble(double arr[], int len) { // O(n^2)
  double temp;
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1; j++) {
      if (j >= len - 1 - i) break;
      else if (arr[j] >= arr[j + 1]) {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    } 
  }
}

static void print(double arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("# %.1lf ", arr[i]);
  }

  printf("#");
}

sort_t create_sort() {
  sort_t *sort = (sort_t *) malloc(sizeof(sort_t));
  sort->merge = merge;
  sort->bubble = bubble;
  sort->print = print;
  return *sort;
}
