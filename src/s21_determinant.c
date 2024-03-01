#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = -1;
  if (!s21_check_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    error = CALCULATION_ERROR;
  } else {
    error = OK;
    *result = s21_find_determinant(A, A->rows, &error);
  }
  return error;
}