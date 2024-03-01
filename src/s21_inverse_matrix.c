#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (!s21_check_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    error = CALCULATION_ERROR;
  }
  if (error == OK) {
    double result_det = 0;
    error = s21_determinant(A, &result_det);
    if (error != OK || fabs(result_det) < ACCURACY) {
      error = CALCULATION_ERROR;
    }
    matrix_t temp = {0};
    if (s21_calc_complements(A, &temp)) {
      error = INCORRECT_MATRIX;
    }
    matrix_t transpose = {0};

    if (s21_transpose(&temp, &transpose) ||
        s21_create_matrix(A->rows, A->rows, result))
      error = INCORRECT_MATRIX;

    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->rows; j++)
        result->matrix[i][j] = transpose.matrix[i][j] / result_det;

    s21_remove_matrix(&transpose);
    s21_remove_matrix(&temp);
  }
  return error;
}
