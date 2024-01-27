#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!A || !result || A->rows != A->columns) {
    return INVALID_MATRIX;
  }
  if (A->rows == 1) {
    *result = A->matrix[0][0];
    return OK;
  }
  *result = 0;
  int sign = 1;

  for (int i = 0; i < A->rows; i++) {
    double minor_deter = minor_determinant(A, 0, i);
    *result = *result + (sign * minor_deter * A->matrix[0][i]);
    sign = -sign;
  }
  return OK;
}

double minor_determinant(matrix_t *A, int rows, int columns) {
  matrix_t minor;
  double result_minor = 0.0;
  int minor_rows = 0, minor_columns = 0;
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
  for (int i = 0; i < A->rows; i++) {
    minor_columns = 0;
    for (int j = 0; j < A->columns; j++) {
      if ((i != rows) && (j != columns)) {
        minor.matrix[minor_rows][minor_columns] = A->matrix[i][j];
        minor_columns++;
      }
    }
    if (i != rows) {
      minor_rows++;
    }
  }
  s21_determinant(&minor, &result_minor);
  s21_remove_matrix(&minor);
  return result_minor;
}
