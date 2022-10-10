#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    if (A->rows != A->columns)
        return CALC_ERROR;

    if (s21_create_matrix(A->rows, A->columns, result) == OK) {
        double tmp_res;
        matrix_t tmp_matrix;

        for (int row = 0; row < A->rows; row++) {
            for (int col = 0; col < A->columns; col++) {
                s21_crop_matrix(A, row, col, &tmp_matrix);
                if (s21_determinant(&tmp_matrix, &tmp_res) == OK) {
                    s21_remove_matrix(&tmp_matrix);
                }

                    result->matrix[row][col] = tmp_res * ((row + col) % 2 ? -1 : 1);
            }
        }
    }
    return OK;
}
