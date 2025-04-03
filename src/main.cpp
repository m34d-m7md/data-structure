#include <stdio.h>
#include "../include/data_structure.hpp"

using data_structure::Sort;

int main() {
  double arr[] = {3.4, 1.4, 6.3, 2.4, 1.3, 5.6, 2.9, 0.5, 3.6, 6.4, 3.6, 2.7, 5.3};

  Sort<double>::bubble(arr, 13);

  for (int i = 0; i < 13; i++) {
    printf("# %.1lf ", arr[i]);
  }

  printf("#");

  return 0;
}
