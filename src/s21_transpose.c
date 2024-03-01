#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = INCORRECT_MATRIX;
  if (s21_null_check(A) || s21_null_check(result)) {
    error = INCORRECT_MATRIX;
  } else if (A->matrix && s21_check_matrix(A)) {
    error = s21_create_matrix(A->columns, A->rows, result);
    if (error == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] += A->matrix[i][j];
        }
      }
    }
  }
  return error;
}