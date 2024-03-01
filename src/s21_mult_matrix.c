#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = INCORRECT_MATRIX;
  if (s21_null_check(A) || s21_null_check(B) || s21_null_check(result)) {
    error = INCORRECT_MATRIX;
  } else if (A->matrix && B->matrix && s21_check_matrix(A) &&
             s21_check_matrix(B)) {
    error = s21_create_matrix(A->rows, B->columns, result);
    if (error == OK) {
      if (A->columns != B->rows) {
        error = CALCULATION_ERROR;
      } else {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    }
  }
  return error;
}