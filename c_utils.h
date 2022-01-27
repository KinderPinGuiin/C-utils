/**
 * A set of macro-functions that make the code more readable.
 * 
 * @author Jordan ELIE.
 */

#ifndef C_UTILS
#define C_UTILS

#include <errno.h>

/*
 * ##################
 * # Error handling #
 * ##################
 */

/**
 * If val is less than 0 :
 * - "Error at line x" is printed with x the current line of your program. 
 * - If errno is greater than 0 then a perror is executed.
 * - Finally, it return EXIT_FAILURE.
 * 
 * @note Non thread safe (Use of errno).
 * @param val The value.
 */
#define CHECK_ERR(val)                                                         \
  do {                                                                         \
    if ((val) < 0) {                                                           \
      fprintf(stderr, "Error at line %d", __LINE__);                           \
      if (errno > 0) {                                                         \
        perror(" ");                                                           \
      } else {                                                                 \
        fprintf(stderr, "\n");                                                 \
      }                                                                        \
      return EXIT_FAILURE;                                                     \
    }                                                                          \
  } while(0)

/**
 * If val is less than 0 :
 * - The variable r is set to EXIT_FAILURE.
 * - "Error at line x" is printed with x the current line of your program. 
 * - If errno is greater than 0 then a perror is executed.
 * - goto the label free in your function.
 * 
 * @note Non thread safe (Use of errno).
 * @param val The value.
 */
#define CHECK_ERR_AND_FREE(val)                                                \
  do {                                                                         \
    if ((val) < 0) {                                                           \
      r = EXIT_FAILURE;                                                        \
      fprintf(stderr, "Error at line %d ", __LINE__);                          \
      if (errno > 0) {                                                         \
        perror("");                                                            \
        errno = 0;                                                             \
      } else {                                                                 \
        fprintf(stderr, "\n");                                                 \
      }                                                                        \
      goto free;                                                               \
    }                                                                          \
  } while(0)

#endif
