#include <stdlib.h>
#include "array.h"

void array_init(Array *array, size_t size) {
  array->values = (int *) malloc(size * sizeof(int));
  array->used = 0;
  array->size = size;
}

void array_fit(Array *array, size_t size) {
  if (size <= array->size) {
    return;
  }

  array->size *= 2;
  array->values = (int *) realloc(array->values, array->size * sizeof(int));
}

void array_insert(Array *array, size_t position, int element) {
  array_fit(array, array->used + 1);
  for (size_t i = array->used; i > position; --i) {
    array->values[i] = array->values[i - 1];
  }
  array->values[position] = element;
  ++array->used;
}

void array_free(Array *array) {
  free(array->values);
  array->values = NULL;
  array->used = 0;
  array->size = 0;
}
