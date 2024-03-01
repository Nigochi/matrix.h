#include "s21_matrix.h"

void s21_init_matrix(matrix_t *result) {
  int rows = result->rows;
  int column = result->columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(column, sizeof(double));
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < column; j++) {
      result->matrix[i][j] = 0;
    }
  }
}

int s21_check_matrix(matrix_t *matrix) {
  int error;
  if (matrix != NULL && matrix->matrix != NULL && matrix->columns > 0 &&
      matrix->rows > 0) {
    error = 1;
  } else {
    error = 0;
  }
  return error;
}

int s21_check_eq_param(matrix_t *A, matrix_t *B) {
  int error = OK;
  if (A->columns != B->columns || A->rows != B->rows) {
    error = CALCULATION_ERROR;
  }
  return error;
}

int s21_check_all(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (s21_check_eq_param(A, B) != OK || s21_check_eq_param(A, result) != OK ||
      s21_check_eq_param(B, result) != OK) {
    error = CALCULATION_ERROR;
  }
  return error;
}

void s21_remove_row_and_column(matrix_t source, matrix_t *minor,
                               int move_column, int move_row) {
  int shift_column = 0, shift_row = 0;
  for (int row = 0; row < source.rows - 1; row++) {
    shift_column = 0;
    if (row == move_row) {
      shift_row = 1;
    }
    for (int column = 0; column < source.columns - 1; column++) {
      if (column == move_column) {
        shift_column = 1;
      }
      minor->matrix[row][column] =
          source.matrix[row + shift_row][column + shift_column];
    }
  }
}

double s21_find_determinant(matrix_t *A, int size, int *error) {
  double result = 0;
  *error = OK;
  int k = 1;
  if (size == 1) {
    result = A->matrix[0][0];
  } else if (size == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    matrix_t minor = {0};
    if (s21_create_matrix(size, size, &minor) != OK) {
      *error = INCORRECT_MATRIX;
    }
    for (int i = 0; i < size; i++) {
      if (size - 1 < 1) {
        break;
      }
      s21_remove_row_and_column(*A, &minor, i, 0);
      result +=
          k * A->matrix[0][i] * s21_find_determinant(&minor, size - 1, error);
      k = -k;
    }
    s21_remove_matrix(&minor);
  }
  return result;
}

void s21_alg_add(matrix_t *A, matrix_t *result, int *error) {
  int size = A->columns;
  int sign = 1;
  matrix_t minor = {0};
  if (s21_create_matrix(size, size, &minor) != OK) {
    *error = INCORRECT_MATRIX;
  }
  if (size == 1) {
    result->matrix[0][0] = 1;
  }
  if (size > 1) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        s21_remove_row_and_column(*A, &minor, j, i);
        if ((i + j) % 2 == 0) {
          sign = 1;
        } else {
          sign = -1;
        }
        result->matrix[i][j] =
            sign * s21_find_determinant(&minor, size - 1, error);
      }
    }
  }
  s21_remove_matrix(&minor);
}

int s21_null_check(matrix_t *A) {
  int error = OK;
  if (A == NULL) {
    error = INCORRECT_MATRIX;
  }
  return error;
}