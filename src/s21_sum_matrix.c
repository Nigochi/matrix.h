#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = INCORRECT_MATRIX;
  if (s21_check_matrix(A) && s21_check_matrix(B)) {
    error = s21_create_matrix(A->rows, B->columns, result);
    if (s21_check_all(A, B, result) != OK) {
      error = CALCULATION_ERROR;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return error;
}