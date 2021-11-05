#include <stdlib.h>
#include <stdio.h>
#include "did_it_in_c/array.h"

Array *array_new(size_t size) {
  Array *array = malloc(sizeof(*array));
  if (!array) {
    perror("Failed to allocate array");
    exit(EXIT_FAILURE);
  }

  array_init(array, size);
  return array;
}

void array_init(Array *array, size_t size) {
  if (size == 0) {
    perror("Array size must be > 0");
    exit(EXIT_FAILURE);
  }

  array->values = (int *) malloc(size * sizeof(int));
  if (!array->values) {
    perror("Failed to allocate array values");
    exit(EXIT_FAILURE);
  }

  array->used = 0;
  array->size = size;
}

void array_fit(Array *array, size_t size) {
  if (size <= array->size) {
    return;
  }

  while (array->size < size) array->size *= 2;
  array->values = (int *) realloc(array->values, array->size * sizeof(int));
  if (!array->values) {
    perror("Failed to allocate array values");
    exit(EXIT_FAILURE);
  }
}

void array_insert(Array *array, size_t position, int element) {
  array_fit(array, position + 1);
  for (size_t i = array->used; i > position; --i) {
    array->values[i] = array->values[i - 1];
  }
  array->values[position] = element;
  ++array->used;
}

void array_set(Array *array, size_t position, int element) {
  array_fit(array, position + 1);
  array->values[position] = element;
  if (array->used <= position) array->used = position + 1;
}

void array_free(Array *array) {
  free(array->values);
  array->values = NULL;
  array->used = 0;
  array->size = 0;
}

void array() {
  Array a;
  array_init(&a, 10);
  for (size_t i = 0; i < a.size; ++i) {
    array_set(&a, i, (int) i);
  }
  array_fit(&a, 20);
  for (size_t i = 10; i < a.size; ++i) {
    array_insert(&a, i, (int) i);
  }
  for (size_t i = 0; i < a.size; ++i) {
    printf("%u ", a.values[i]);
  }
  array_free(&a);
  printf("\n");
}
