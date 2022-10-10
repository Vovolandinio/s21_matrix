#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    if (A->rows != A->columns)
        return CALC_ERROR;

    int status = OK;

    if (A->rows == 0) {
        return CALC_ERROR;
    } else if (A->rows == 1) {
        *result = A->matrix[0][0];
    } else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
        *result = 0;

        matrix_t minor;

        double tmp;
        for (int row = 0; status == OK && row < A->rows; row++) {
            if (s21_crop_matrix(A, row, 0, &minor) == OK) {
                status = s21_determinant(&minor, &tmp);
                if (status == OK) {
                    *result += tmp * A->matrix[row][0] * ((row % 2) ? -1 : 1);
                }
            }
            s21_remove_matrix(&minor);
        }
    }
    return status;
}
