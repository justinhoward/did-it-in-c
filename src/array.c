#include <stdlib.h>
#include <stdio.h>
#include "did_it_in_c/array.h"
#include "did_it_in_c/error.h"

Array *array_new(size_t size) {
  Array *array = malloc(sizeof(*array));
  if (!array) FATAL_ERR("Failed to allocate array");

  array_init(array, size);
  return array;
}

void array_init(Array *array, size_t size) {
  if (size == 0) FATAL_ERR("Array size must be > 0");

  array->values = (int *) malloc(size * sizeof(int));
  if (!array->values) FATAL_ERR("Failed to allocate array");

  array->used = 0;
  array->size = size;
}

void array_fit(Array *array, size_t size) {
  if (size <= array->size) {
    return;
  }

  while (array->size < size) array->size *= 2;
  array->values = (int *) realloc(array->values, array->size * sizeof(int));
  if (!array->values) perror("Failed to allocate array values");
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

void array_example() {
  Array *a = array_new(10);
  array_init(a, 10);
  for (size_t i = 0; i < a->size; ++i) {
    array_set(a, i, (int) i);
  }
  array_fit(a, 20);
  for (size_t i = 10; i < a->size; ++i) {
    array_insert(a, i, (int) i);
  }
  for (size_t i = 0; i < a->size; ++i) {
    printf("%i ", a->values[i]);
  }
  printf("\n");

  array_free(a);
  free(a);
}
