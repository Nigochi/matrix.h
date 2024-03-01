#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error;
  if (rows > 0 && columns > 0 && result) {
    error = OK;
    result->rows = rows;
    result->columns = columns;
    s21_init_matrix(result);
  } else if (result) {
    error = INCORRECT_MATRIX;
    result->matrix = NULL;
  } else {
    error = INCORRECT_MATRIX;
  }
  return error;
}