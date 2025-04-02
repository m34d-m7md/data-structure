#include <stdio.h>
#include "../include/data_structure.h"

using data_structure::Sort;

int main() {
  double arr[] = {3.4, 1.4, 6.3, 2.4, 1.3, 5.6, 2.9, 0.5, 3.6};

  Sort<double>::bubble(arr, 9);

  for (int i = 0; i < 9; i++) {
    printf("# %.1lf ", arr[i]);
  }

  printf("#");

  return 0;
}
