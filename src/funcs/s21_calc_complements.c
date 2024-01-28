#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A->rows != A->columns) {
    return CALC_ERROR;
  }
  if (A->rows <= 0 && A->columns <= 0) {
    return INVALID_MATRIX;
  }

  s21_create_matrix(A->rows, A->columns, result);
 
  for (int i = 0; A->rows; i++) {
    for (int j = 0; A->columns; j++) {
      result->matrix[i][j] = minor_determinant(A, i, j) * pow(-1, (i + j));
    }
  }
  return OK;
}
