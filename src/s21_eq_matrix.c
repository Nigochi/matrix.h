#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = -1;
  if (s21_null_check(A) || s21_null_check(B)) {
    error = FAILURE;
  } else if (s21_check_matrix(A) && s21_check_matrix(B) &&
             (A->columns == B->columns) && (A->rows == B->rows)) {
    error = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > ACCURACY) {
          error = FAILURE;
          break;
        }
      }
      if (!error) {
        break;
      }
    }
  } else {
    error = FAILURE;
  }
  return error;
}