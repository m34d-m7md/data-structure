#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdlib.h>
#include <iostream>

typedef unsigned long long size_t;

namespace data_structure {
  template <typename T>
  struct Node {
    T value;
    Node *next;
  };

  template <typename T>
  class LinkedList {
    private:
      Node<T> *head;
      size_t len;

      Node<T> *create_node(T value) {
        Node<T> *node = (Node<T> *) malloc(sizeof(Node<T>));
        node->value = value;
        node->next = NULL;
        return node;
      }
    public:
      LinkedList() {
        this->head = NULL;
        this->len = 0;
      }

      // ---- O(n) time complexity ----

      bool add(size_t index, T value) {
        if (index > this->len) return false;
      
        Node<T> *node = create_node(value);
        int len = this->len++;
      
        if (index == 0) {
          node->next = this->head;
          this->head = node;
      
          return true;
        }

        Node<T> *curr = this->head;
    
        for (int i = 0; i < index - 1; i++) curr = curr->next;
      
        if (index ==  len) {
          curr->next = node;
          return true;
        }
      
        node->next = curr->next;
        curr->next = node;
      
        return true;
      }

      // ---- O(n) time complexity ----

      T drop(size_t index) {
        if (index > this->len) return 0.0;
      
        Node<T> *temp;
        T value;
        this->len--;
      
        if (index == 0) {
          temp = this->head;
          value = temp->value;
          this->head = this->head->next;
          free(temp);
      
          return value;
        }
      
        Node<T> *curr = this->head;
      
        for (int i = 0; i < index - 1; i++) curr = curr->next;
      
        temp = curr->next;
        value = temp->value;
        curr->next = curr->next->next;
        free(temp);
      
        return value;
      }

      // ---- O(n) time complexity ----

      T get(size_t index) {
        if (index >= this->len) return 0.0;
      
        Node<T> *curr = this->head;
      
        for (int i = 0; i < index; i++) curr = curr->next;
      
        return curr->value;
      }
  
      // ---- ==== ==== ==== ----

  };

  template <typename T>
  class Sort {
    public:

      // ---- O(nlog(n)) time complexity ----
      // ---- O(n) space complexity ----
      
      static void merge(T arr[], int len) {
        if (len <= 1) return;
      
        int left_len = len / 2;
        int right_len = len - left_len;
        T *left = (T *) malloc(sizeof(T) * left_len);
        T *right = (T *) malloc(sizeof(T) * right_len);
      
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
  
      
      // ---- O(n^2) time complexity ----
      // ---- O(1) space complexity ----

      static void bubble(T arr[], int len) {
        T temp;
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
  
      // ---- ==== ==== ==== ----

  };
}

#endif
