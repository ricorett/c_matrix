#include <check.h>
#include <math.h>
#include <stdlib.h>
// #include "/opt/homebrew/opt/check/include/check.h"
//  #include "/opt/homebrew/opt/lcov/include/"

#define ACCURACY 1e-7
#define SUCCESS 1
#define FAILURE 0
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum {
  OK,
  INVALID_MATRIX,
  CALC_ERROR,
} stat;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
// double minor_determinant(matrix_t *A, int columns, int rows);
void s21_copy_matrix(matrix_t *A, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int shrink(matrix_t *m, matrix_t *result, int i, int j);
int s21_minor(matrix_t *A, int x, int y, double *result);