#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct {
  int *values;
  size_t used;
  size_t size;
} Array;

void array_init(Array *array, size_t size);
void array_fit(Array *array, size_t size);
void array_insert(Array *array, size_t index, int element);
void array_free(Array *array);
void array();

#endif
