#include "../inc/sort.h"
#include "../inc/linked_list.h"

int main() {

  sort_t sort = create_sort();
  linked_list_t list = create_linked_list();
  double arr[] = {1.0, 9.4, 3.4, 2.4, 1.2, 1.2, 8.1, 6.2, 1.4, 5.1, 7.3, 8.2, 5.2, 1.7, 4.7};
  printf("\n");

  // sorting
  
  sort.merge(arr, 15);
  printf("After sorting:\n");
  sort.print(arr, 15);
  printf("\n\n");

  // linked list

  for (int i = 0; i < 15; i++) list.add(&list, list.len, arr[i]);

  list.drop(&list, 2);
  printf("Linked list:\n");
  list.print(&list);
  printf("\n\n");

  return 0;
}