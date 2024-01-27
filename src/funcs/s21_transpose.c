#include "../s21_matrix.h"
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->rows != result->columns ||
      A->columns != result->rows) {
    return INVALID_MATRIX;
  }

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return OK;
}
