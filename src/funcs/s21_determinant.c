#include "../s21_matrix.h"

// int s21_determinant(matrix_t *A, double *result) {
//   if (A == NULL || result == NULL) {
//     return INVALID_MATRIX;
//   }

//   if(A->rows != A->columns){
//     return CALC_ERROR;
//   }

//    if (A->rows <= 0 && A->columns <= 0) {
//     return INVALID_MATRIX;
//   }

//   if (A->rows == 1) {
//     *result = A->matrix[0][0];
//     return OK;
//   }
//   *result = 0;
//   int sign = 1;

//   for (int i = 0; i < A->rows; i++) {
//     double minor_deter = minor_determinant(A, 0, i);
//     *result = *result + (sign * minor_deter * A->matrix[0][i]);
//     sign = -sign;
//   }
//   return OK;
// }

// double minor_determinant(matrix_t *A, int rows, int columns) {
//   matrix_t minor;
//   double result_minor = 0.0;
//   int minor_rows = 0, minor_columns = 0;
//   s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
//   for (int i = 0; i < A->rows; i++) {
//     minor_columns = 0;
//     for (int j = 0; j < A->columns; j++) {
//       if ((i != rows) && (j != columns)) {
//         minor.matrix[minor_rows][minor_columns] = A->matrix[i][j];
//         minor_columns++;
//       }
//     }
//     if (i != rows) {
//       minor_rows++;
//     }
//   }
//   s21_determinant(&minor, &result_minor);
//   s21_remove_matrix(&minor);
//   return result_minor;
// }

int s21_determinant(matrix_t *A, double *result)
{

    if (A == NULL){
      return INVALID_MATRIX;
    }
    if  (A->rows != A->columns){
      return CALC_ERROR;
    }

    if  ((A->rows <= 0) || (A->columns <= 0)){
      return INVALID_MATRIX;
    }

    double res = 0;
    if (A->rows == 1 && A-> columns == 1)
    {
        *result = A->matrix[0][0];
        return OK;
    }
    for(int j = 0; j < A->columns; j++)
    {
        matrix_t tmp;
        s21_create_matrix(A->rows-1, A->columns-1, &tmp);
        if (result == NULL){
          return INVALID_MATRIX;
        }
        shrink(A, &tmp, 0, j);
        int _t = ((0 + j) % 2) ? -1 : 1;
        double _r = 0;
        s21_determinant(&tmp, &_r);
        res += _t * A->matrix[0][j] * _r;
        s21_remove_matrix(&tmp);
    }
    *result = res;
    return OK;
}

int shrink(matrix_t *A, matrix_t *result, int i, int j)
{
    int u = 0, v = 0;
    for (int k = 0; k < A->rows; k++)
    {
        v = 0;
        if (k == i) continue;
        for (int l = 0; l < A->columns; l++)
        {
            if (l == j) continue;
            result->matrix[u][v] = A->matrix[k][l];
            v++;
        }
        u++;
    }
    return OK;
}

int s21_minor(matrix_t *A, int x, int y, double *result)
{
    matrix_t tmp;
    s21_create_matrix(A->rows-1, A->columns-1, &tmp);
    shrink(A, &tmp, x, y);
    s21_determinant(&tmp, result);
    s21_remove_matrix(&tmp);
    return OK;
}