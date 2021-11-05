#ifndef INCLUDE_DID_IT_IN_C_ARRAY_H_
#define INCLUDE_DID_IT_IN_C_ARRAY_H_

#include <stdlib.h>

typedef struct {
  int *values;
  size_t used;
  size_t size;
} Array;

Array *array_new(size_t size);
void array_init(Array *array, size_t size);
void array_fit(Array *array, size_t size);
void array_insert(Array *array, size_t index, int element);
void array_set(Array *array, size_t index, int element);
void array_free(Array *array);
void array(void);

#endif  // INCLUDE_DID_IT_IN_C_ARRAY_H_
