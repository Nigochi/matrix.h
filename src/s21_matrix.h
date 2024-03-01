#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define ACCURACY 1e-07

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum { OK = 0, INCORRECT_MATRIX = 1, CALCULATION_ERROR = 2 } errors;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// s21_help.c
void s21_init_matrix(matrix_t *result);
int s21_check_matrix(matrix_t *matrix);
int s21_check_eq_param(matrix_t *A, matrix_t *B);
int s21_check_all(matrix_t *A, matrix_t *B, matrix_t *result);
void s21_remove_row_and_column(matrix_t source, matrix_t *minor,
                               int move_column, int move_row);
double s21_find_determinant(matrix_t *A, int size, int *error);
void s21_alg_add(matrix_t *A, matrix_t *result, int *error);
int s21_null_check(matrix_t *A);

#endif  // S21_MATRIX_H_
