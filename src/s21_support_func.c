#include "s21_matrix.h"

int s21_eq_size_matrix(matrix_t *A, matrix_t *B) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
        return OK;
    } else {
        return INCORRECT_MATRIX;
    }
}


int s21_crop_matrix(matrix_t *A, int del_row, int del_col, matrix_t *B) {
    if (s21_create_matrix(A->rows - 1, A->columns - 1, B) == OK) {
        for (int row = 0, row1 = 0; row < A->rows; row++) {
            if (row == del_row)
                continue;
            for (int col = 0, col1 = 0; col < A->columns; col++) {
                if (col == del_col)
                    continue;

                B->matrix[row1][col1] = A->matrix[row][col];
                col1++;
            }
            row1++;
        }
        return OK;
    } else {
        return INCORRECT_MATRIX;
    }
}
