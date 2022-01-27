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

#ifdef VERBOSE

/**
 * If val is less than 0 :
 * - "Error at line x" is printed with x the current line of your program. 
 * - If errno is greater than 0 then a perror is executed.
 * - Finally, it exit with the code EXIT_FAILURE.
 * 
 * @note Non thread safe (Use of errno).
 * @param val The value.
 */
#define CHECK_ERR_AND_EXIT(val)                                                \
  do {                                                                         \
    if ((val) < 0) {                                                           \
      fprintf(stderr, "Error at line %d", __LINE__);                           \
      if (errno > 0) {                                                         \
        perror(" ");                                                           \
      } else {                                                                 \
        fprintf(stderr, "\n");                                                 \
      }                                                                        \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while(0)

/**
 * If val is less than 0 :
 * - The variable r is set to r_val.
 * - "Error at line x" is printed with x the current line of your program. 
 * - If errno is greater than 0 then a perror is executed.
 * - goto the label free in your function.
 * 
 * @note Non thread safe (Use of errno).
 * @param val The value.
 * @param r_val The return value of the function.
 */
#define CHECK_ERR_AND_FREE(val, r_val)                                         \
  do {                                                                         \
    if ((val) < 0) {                                                           \
      r = r_val;                                                               \
      fprintf(stderr, "Error at line %d", __LINE__);                           \
      if (errno > 0) {                                                         \
        perror(" ");                                                           \
        errno = 0;                                                             \
      } else {                                                                 \
        fprintf(stderr, "\n");                                                 \
      }                                                                        \
      goto free;                                                               \
    }                                                                          \
  } while(0)

/**
 * If val is less than 0 :
 * - "Error at line x" is printed with x the current line of your program. 
 * - If errno is greater than 0 then a perror is executed.
 * - return with r_val
 * 
 * @note Non thread safe (Use of errno).
 * @param val The value.
 * @param r_val The return value of the function.
 */
#define CHECK_ERR_AND_RETURN(val, r_val)                                       \
  do {                                                                         \
    if ((val) < 0) {                                                           \
      fprintf(stderr, "Error at line %d", __LINE__);                           \
      if (errno > 0) {                                                         \
        perror(" ");                                                           \
        errno = 0;                                                             \
      } else {                                                                 \
        fprintf(stderr, "\n");                                                 \
      }                                                                        \
      return r_val;                                                            \
    }                                                                          \
  } while(0)

#else

/**
 * If val is less than 0 :
 * - Exit with the code EXIT_FAILURE.
 * 
 * @note Thread safe.
 * @param val The value.
 */
#define CHECK_ERR_AND_EXIT(val)                                                \
  do { if ((val) < 0) { exit(EXIT_FAILURE); } } while(0)

/**
 * If val is less than 0 :
 * - The variable r is set to r_val.
 * - goto the label free in your function.
 * 
 * @note Thread safe.
 * @param val The value.
 * @param r_val The return value of the function.
 */
#define CHECK_ERR_AND_FREE(val, r_val)                                         \
  do {                                                                         \
    if ((val) < 0) {                                                           \
      r = r_val;                                                               \
      goto free;                                                               \
    }                                                                          \
  } while(0)

/**
 * If val is less than 0 :
 * - return with r_val
 * 
 * @note Thread safe.
 * @param val The value.
 * @param r_val The return value of the function.
 */
#define CHECK_ERR_AND_RETURN(val, r_val)                                       \
  do {                                                                         \
    if ((val) < 0) {                                                           \
      return r_val;                                                            \
    }                                                                          \
  } while(0)

#endif

#endif
