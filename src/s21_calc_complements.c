#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = -1;
  if (!s21_check_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    error = CALCULATION_ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
      error = INCORRECT_MATRIX;
    } else {
      error = OK;
      s21_alg_add(A, result, &error);
    }
  }
  return error;
}
