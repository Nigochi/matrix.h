#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = s21_null_check(A);
  if (s21_check_matrix(A) && error != 1) {
    error = s21_create_matrix(A->rows, A->columns, result);
    error = s21_check_eq_param(A, result);
    if (error == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return error;
}
