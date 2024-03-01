#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

START_TEST(s21_create_matrix_test_1) {
  int rows = 4, columns = 4;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  int rows = -1, columns = -1;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(res, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {
  int rows = 0, columns = 0;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(res, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_4) {
  int rows = 1, columns = 0;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(res, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_5) {
  int rows = 0, columns = 1;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(res, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_6) {
  int rows = 1, columns = 1;
  matrix_t A = {0};

  int res = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_7) {
  int rows = 25, cols = 5;

  int ret_val = s21_create_matrix(rows, cols, NULL);

  ck_assert_int_eq(ret_val, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_eq_matrix_test_1) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = -5.0;
  A.matrix[0][1] = 3.0;
  A.matrix[0][2] = 87.0;
  A.matrix[1][0] = -71.0;
  A.matrix[1][1] = -25.0;
  A.matrix[1][2] = 69.0;

  B.matrix[0][0] = -4.9999999425;
  B.matrix[0][1] = 3.0000000984;
  B.matrix[0][2] = 86.9999999163;
  B.matrix[1][0] = -71.000000029;
  B.matrix[1][1] = -24.999999967;
  B.matrix[1][2] = 68.999999975;

  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  int rows = 4, columns = 4;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 89.0;
  A.matrix[0][1] = 15.0;
  A.matrix[0][2] = -73.0;
  A.matrix[0][3] = 84.0;
  A.matrix[1][0] = -48.0;
  A.matrix[1][1] = 98.0;
  A.matrix[1][2] = -37.0;
  A.matrix[1][3] = -15.0;
  A.matrix[2][0] = -65.0;
  A.matrix[2][1] = 9.0;
  A.matrix[2][2] = 65.0;
  A.matrix[2][3] = -39.0;
  A.matrix[3][0] = 98.0;
  A.matrix[3][1] = -76.0;
  A.matrix[3][2] = -36.0;
  A.matrix[3][3] = -80.0;

  B.matrix[0][0] = 89.000000036;
  B.matrix[0][1] = 15.000000094;
  B.matrix[0][2] = -72.9999999;
  B.matrix[0][3] = 83.999999974;
  B.matrix[1][0] = -48.00000008;
  B.matrix[1][1] = 97.9999999;
  B.matrix[1][2] = -37.000000032;
  B.matrix[1][3] = -14.999999956;
  B.matrix[2][0] = -65.000000001;
  B.matrix[2][1] = 9.00000006656;
  B.matrix[2][2] = 65.0000000896;
  B.matrix[2][3] = -38.99999992;
  B.matrix[3][0] = 97.999999968;
  B.matrix[3][1] = -76.00000002;
  B.matrix[3][2] = -36.00000005;
  B.matrix[3][3] = -79.99999996;

  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  int rows = 1, columns = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 1, columns - 1, &B);

  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  int rows1 = 2, columns1 = 1;
  matrix_t A = {0};
  s21_create_matrix(rows1, columns1, &A);

  int res = s21_eq_matrix(&A, NULL);

  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_test_5) {
  int rows = 2, columns = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns + 2, &B);

  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_7) {
  int rows = 2, columns = 1;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 4, columns + 1, &B);

  int res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_6) {
  int rows = 3;
  int columns = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 2.2;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8.45;
  A.matrix[1][1] = 8;
  A.matrix[2][0] = 10;
  A.matrix[2][1] = 654;

  B.matrix[0][0] = 2;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 8.45;
  B.matrix[1][1] = 8;
  B.matrix[2][0] = 10;
  B.matrix[2][1] = 654;

  int check_error = FAILURE;
  int error = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(error, check_error);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_test_1) {
  int rows = 3, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -2;

  int status = s21_transpose(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 1, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], 0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 1, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], -2, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  int rows = 5, columns = 1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = -701.0;
  A.matrix[1][0] = -991.0;
  A.matrix[2][0] = -694.0;
  A.matrix[3][0] = -433.0;
  A.matrix[4][0] = -930.0;

  int status = s21_transpose(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -701.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -991.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -694.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][3], -433.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][4], -930.0, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  int error = s21_transpose(&A, &result);

  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 1, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 4, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 2, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 5, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][0], 3, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][1], 6, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_4) {
  int rows1 = 5, cols1 = 1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows1, cols1, &A);
  A.matrix[0][0] = -60.0;
  A.matrix[1][0] = 16.0;
  A.matrix[2][0] = 24.0;
  A.matrix[3][0] = -49.0;
  A.matrix[4][0] = 80.0;
  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -60.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 16.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], 24.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][3], -49.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][4], 80.0, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_5) {
  matrix_t result = {0};

  int status = s21_transpose(NULL, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_6) {
  matrix_t A = {0};

  int status = s21_transpose(&A, NULL);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_matrix_test_1) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);

  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = -2.5;
  A.matrix[0][2] = 0.3;
  A.matrix[1][0] = 47;
  A.matrix[1][1] = -0.001;
  A.matrix[1][2] = 6;

  B.matrix[0][0] = -1;
  B.matrix[0][1] = 8.5;
  B.matrix[1][0] = 3.321321;
  B.matrix[1][1] = 4.1;
  B.matrix[2][0] = 5;
  B.matrix[2][1] = 6;

  int error = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -8.303303, 0.000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.3, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][0], -17.003321, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 435.4959, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  int rows = 1, columns = 5;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 4, columns, &B);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = -1;
  A.matrix[0][3] = 0;
  A.matrix[0][4] = 1;

  B.matrix[0][0] = -8;
  B.matrix[0][1] = 4;
  B.matrix[0][2] = 2;
  B.matrix[0][3] = -7;
  B.matrix[0][4] = -4;
  B.matrix[1][0] = -10;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = -6;
  B.matrix[1][3] = -3;
  B.matrix[1][4] = 8;
  B.matrix[2][0] = 4;
  B.matrix[2][1] = -1;
  B.matrix[2][2] = 3;
  B.matrix[2][3] = 1;
  B.matrix[2][4] = -1;
  B.matrix[3][0] = -9;
  B.matrix[3][1] = -8;
  B.matrix[3][2] = 6;
  B.matrix[3][3] = 3;
  B.matrix[3][4] = 1;
  B.matrix[4][0] = 5;
  B.matrix[4][1] = 1;
  B.matrix[4][2] = -9;
  B.matrix[4][3] = 5;
  B.matrix[4][4] = -7;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(B.columns, result.columns);
  ck_assert_int_eq(A.rows, result.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], -9.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 2.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -18.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][3], 1.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][4], 2.0, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);

  int status = s21_mult_matrix(&A, NULL, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  int rows = 2, columns = 2;
  matrix_t B = {0}, result = {0};
  s21_create_matrix(rows, columns, &B);

  int status = s21_mult_matrix(NULL, &B, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_1) {
  int rows = 2, columns = 3;
  double number = 2.456456;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  // s21_create_matrix(rows, columns, &result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;

  int error = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[0][2], 2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][2], 2.456456, 0.000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  int rows = 2, columns = 3;
  double number = -2.456456;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  // s21_create_matrix(rows, columns, &result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;

  int error = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][0], -2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][1], -2.456456, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][2], -2.456456, 0.000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  int rows = 3, columns = 3;
  double number = -7268.448249015911;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = -74.0;
  A.matrix[0][1] = -22.0;
  A.matrix[0][2] = 51.0;
  A.matrix[1][0] = -59.0;
  A.matrix[1][1] = 50.0;
  A.matrix[1][2] = -67.0;
  A.matrix[2][0] = 38.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -76.0;

  int status = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 537865.1704271775, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 159905.86147835004, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -370690.8606998114, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 428838.44669193873, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], -363422.4124507955, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], 486986.03268406604, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][0], -276201.0334626046, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][1], 14536.896498031821, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][2], 552402.0669252092, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_4) {
  matrix_t result = {0};

  int status = s21_mult_number(NULL, 2, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_1) {
  int rows = 3, columns = 3;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1.123;
  A.matrix[0][1] = -0.005;
  A.matrix[0][2] = -0.000001;
  A.matrix[1][0] = 1000;
  A.matrix[1][1] = 486;
  A.matrix[1][2] = 12.3;
  A.matrix[2][0] = -56;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0.000001;
  B.matrix[1][0] = 0.123;
  B.matrix[1][1] = -4.2;
  B.matrix[1][2] = 7.98765489;
  B.matrix[2][0] = -1;
  B.matrix[2][1] = 0;
  B.matrix[2][2] = 534864533;

  int error = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 2.123, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -0.005, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], 0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 1000.123, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 481.8, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], 20.28765489, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][0], -57, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][1], -3, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][2], 534864539, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  int rows = 1, columns = 5;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = -7.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 0.0;
  A.matrix[0][3] = -1.0;
  A.matrix[0][4] = 1.0;

  B.matrix[0][0] = 52.0;
  B.matrix[0][1] = -68.0;
  B.matrix[0][2] = -42.0;
  B.matrix[0][3] = -14.0;
  B.matrix[0][4] = -17.0;

  int status = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 45.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -63.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -42.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][3], -15.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][4], -16.0, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns - 1, &B);

  int status = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);

  int status = s21_sum_matrix(&A, NULL, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_5) {
  matrix_t B = {0}, result = {0};
  s21_create_matrix(2, 2, &B);

  int status = s21_sum_matrix(NULL, &B, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_1) {
  int rows = 3, columns = 3;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 1.123;
  A.matrix[0][1] = -0.005;
  A.matrix[0][2] = -0.000001;
  A.matrix[1][0] = 1000;
  A.matrix[1][1] = 486;
  A.matrix[1][2] = 12.3;
  A.matrix[2][0] = -56;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0.000001;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = -4.2;
  B.matrix[1][2] = 7.98765489;
  B.matrix[2][0] = -1;
  B.matrix[2][1] = 0;
  B.matrix[2][2] = 53486453;

  int error = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 0.123, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -0.005, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -0.000002, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 993, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 490.2, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], 4.31234511, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][0], -55, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][1], -3, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][2], -53486447, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_2) {
  int rows = 3, columns = 3;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.matrix[0][0] = -5.0;
  A.matrix[0][1] = -49.0;
  A.matrix[0][2] = 91.0;
  A.matrix[1][0] = -19.0;
  A.matrix[1][1] = -83.0;
  A.matrix[1][2] = 63.0;
  A.matrix[2][0] = -69.0;
  A.matrix[2][1] = -97.0;
  A.matrix[2][2] = -86.0;

  B.matrix[0][0] = -849.0;
  B.matrix[0][1] = 535.0;
  B.matrix[0][2] = 146.0;
  B.matrix[1][0] = 297.0;
  B.matrix[1][1] = -555.0;
  B.matrix[1][2] = 32.0;
  B.matrix[2][0] = 759.0;
  B.matrix[2][1] = 279.0;
  B.matrix[2][2] = -13.0;

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 844.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -584.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -55.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], -316.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 472.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], 31.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][0], -828.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][1], -376.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][2], -73.0, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_3) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns - 1, &B);

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_4) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);

  int status = s21_sub_matrix(&A, NULL, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_5) {
  int rows = 2, columns = 2;
  matrix_t B = {0}, result = {0};
  s21_create_matrix(rows, columns, &B);

  int status = s21_sub_matrix(NULL, &B, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_1) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 57.0;
  A.matrix[0][1] = -55.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -79.0;

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -79.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -2.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 55.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 57.0, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  int rows = 3, columns = 3;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  // s21_create_matrix(rows, columns, &result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 10;
  A.matrix[0][2] = 8.6;
  A.matrix[1][0] = -78.4;
  A.matrix[1][1] = -0.054;
  A.matrix[1][2] = 0.53;
  A.matrix[2][0] = 154;
  A.matrix[2][1] = 123;
  A.matrix[2][2] = 8;

  int error = s21_calc_complements(&A, &result);

  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -65.622, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 708.82, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -9634.884, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 977.8, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], -1316.4, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], 1417, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][0], 5.7644, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][1], -674.77, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][2], 783.946, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  int rows = 1, columns = 1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  // s21_create_matrix(rows, columns, &check);

  A.matrix[0][0] = 23464;

  int error = s21_calc_complements(&A, &result);
  ck_assert_int_eq(error, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 1, 0.0000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t result = {0};
  int status = s21_calc_complements(NULL, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {
  matrix_t A = {0};
  int status = s21_calc_complements(&A, NULL);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_6) {
  int rows = 3, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);

  int status = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_determinant_test_1) {
  int rows = 4, columns = 4;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][0] = -2;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 5;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 3;
  A.matrix[1][3] = -1;
  A.matrix[2][0] = -1;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 4;
  A.matrix[2][3] = 0;
  A.matrix[3][0] = 3;
  A.matrix[3][1] = 1;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = -1;

  int error = s21_determinant(&A, &result);

  ck_assert_int_eq(error, OK);
  ck_assert_double_eq(result, 78);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  double result = 0;

  A.matrix[0][0] = -55;

  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, -55, 0.0000001);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  int rows = 2, columns = 2;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  double result = 0;

  A.matrix[0][0] = 1;
  A.matrix[0][1] = -1;
  A.matrix[1][0] = -1;
  A.matrix[1][1] = 0;

  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, -1, 0.0000001);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  double result = 0;
  int status = s21_determinant(NULL, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  int rows = 3, columns = 2;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_1) {
  matrix_t A = {0}, result = {0};
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &A);
  // s21_create_matrix(rows, columns, &result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = -8;
  A.matrix[1][1] = -0.02;

  int error = s21_inverse_matrix(&A, &result);
  int check_error = OK;
  ck_assert_int_eq(error, check_error);
  ck_assert_double_eq_tol(result.matrix[0][0], -0.001252, 0.000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -0.125156, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 0.500626, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 0.062578, 0.000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A = {0}, result = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  // s21_create_matrix(rows, columns, &result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 10;
  A.matrix[0][2] = 8.6;
  A.matrix[1][0] = -78.4;
  A.matrix[1][1] = -0.054;
  A.matrix[1][2] = 0.53;
  A.matrix[2][0] = 154;
  A.matrix[2][1] = 123;
  A.matrix[2][2] = 8;

  int error = s21_inverse_matrix(&A, &result);
  int check_error = OK;
  ck_assert_int_eq(error, check_error);
  ck_assert_double_eq_tol(result.matrix[0][0], 0.000865, 0.000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -0.012893, 0.000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -0.000076, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][0], -0.009347, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 0.017358, 0.000001);
  ck_assert_double_eq_tol(result.matrix[1][2], 0.008898, 0.000001);
  ck_assert_double_eq_tol(result.matrix[2][0], 0.127047, 0.000001);
  ck_assert_double_eq_tol(result.matrix[2][1], -0.018685, 0.000001);
  ck_assert_double_eq_tol(result.matrix[2][2], -0.010337, 0.000001);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t result = {0};
  int status = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
  matrix_t A = {0};
  int status = s21_inverse_matrix(&A, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  int rows = 3, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_6) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 25;
  A.matrix[0][1] = 60;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 12;
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite;
  suite = suite_create("s21_matrix");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, s21_create_matrix_test_1);
  tcase_add_test(tcase_core, s21_create_matrix_test_2);
  tcase_add_test(tcase_core, s21_create_matrix_test_3);
  tcase_add_test(tcase_core, s21_create_matrix_test_4);
  tcase_add_test(tcase_core, s21_create_matrix_test_5);
  tcase_add_test(tcase_core, s21_create_matrix_test_6);
  tcase_add_test(tcase_core, s21_create_matrix_test_7);

  tcase_add_test(tcase_core, s21_eq_matrix_test_1);
  tcase_add_test(tcase_core, s21_eq_matrix_test_2);
  tcase_add_test(tcase_core, s21_eq_matrix_test_3);
  tcase_add_test(tcase_core, s21_eq_matrix_test_4);
  tcase_add_test(tcase_core, s21_eq_matrix_test_5);
  tcase_add_test(tcase_core, s21_eq_matrix_test_6);
  tcase_add_test(tcase_core, s21_eq_matrix_test_7);

  tcase_add_test(tcase_core, s21_transpose_test_1);
  tcase_add_test(tcase_core, s21_transpose_test_2);
  tcase_add_test(tcase_core, s21_transpose_test_3);
  tcase_add_test(tcase_core, s21_transpose_test_4);
  tcase_add_test(tcase_core, s21_transpose_test_5);
  tcase_add_test(tcase_core, s21_transpose_test_6);

  tcase_add_test(tcase_core, s21_mult_matrix_test_1);
  tcase_add_test(tcase_core, s21_mult_matrix_test_2);
  tcase_add_test(tcase_core, s21_mult_matrix_test_3);
  tcase_add_test(tcase_core, s21_mult_matrix_test_4);
  tcase_add_test(tcase_core, s21_mult_matrix_test_5);

  tcase_add_test(tcase_core, s21_mult_number_test_1);
  tcase_add_test(tcase_core, s21_mult_number_test_2);
  tcase_add_test(tcase_core, s21_mult_number_test_3);
  tcase_add_test(tcase_core, s21_mult_number_test_4);

  tcase_add_test(tcase_core, s21_sum_matrix_test_1);
  tcase_add_test(tcase_core, s21_sum_matrix_test_2);
  tcase_add_test(tcase_core, s21_sum_matrix_test_3);
  tcase_add_test(tcase_core, s21_sum_matrix_test_4);
  tcase_add_test(tcase_core, s21_sum_matrix_test_5);

  tcase_add_test(tcase_core, s21_sub_matrix_test_1);
  tcase_add_test(tcase_core, s21_sub_matrix_test_2);
  tcase_add_test(tcase_core, s21_sub_matrix_test_3);
  tcase_add_test(tcase_core, s21_sub_matrix_test_4);
  tcase_add_test(tcase_core, s21_sub_matrix_test_5);

  tcase_add_test(tcase_core, s21_calc_complements_test_1);
  tcase_add_test(tcase_core, s21_calc_complements_test_2);
  tcase_add_test(tcase_core, s21_calc_complements_test_3);
  tcase_add_test(tcase_core, s21_calc_complements_test_4);
  tcase_add_test(tcase_core, s21_calc_complements_test_5);
  tcase_add_test(tcase_core, s21_calc_complements_test_6);

  tcase_add_test(tcase_core, s21_determinant_test_1);
  tcase_add_test(tcase_core, s21_determinant_test_2);
  tcase_add_test(tcase_core, s21_determinant_test_3);
  tcase_add_test(tcase_core, s21_determinant_test_4);
  tcase_add_test(tcase_core, s21_determinant_test_5);

  tcase_add_test(tcase_core, s21_inverse_matrix_test_1);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_2);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_3);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_4);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_5);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_6);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
