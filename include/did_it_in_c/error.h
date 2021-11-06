#ifndef INCLUDE_DID_IT_IN_C_ERROR_H_
#define INCLUDE_DID_IT_IN_C_ERROR_H_

#include <stdio.h>

#define FATAL_ERR(msg) { \
  perror((msg)); \
  exit(EXIT_FAILURE); \
}

#endif  // INCLUDE_DID_IT_IN_C_ERROR_H_
