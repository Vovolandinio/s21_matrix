#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    if (A->rows != A->columns)
        return CALC_ERROR;

    double det = 0;
    int code = OK;
    if (s21_determinant(A, &det) == OK) {
        if (fabs(det - 0) > EPS) {
            matrix_t tmp_com;

            if (A->rows == 1) {
                s21_create_matrix(1, 1, &tmp_com);
                tmp_com.matrix[0][0] = 1;
            } else {
                code = s21_calc_complements(A, &tmp_com);
            }

            if (code == OK) {
                matrix_t tmp_tranpose;
                code = s21_transpose(&tmp_com, &tmp_tranpose);
                s21_mult_number(&tmp_tranpose, 1.0 / det, result);
                s21_remove_matrix(&tmp_tranpose);
            }
            s21_remove_matrix(&tmp_com);
        } else {
            code = CALC_ERROR;
        }
    }

    return code;
}
