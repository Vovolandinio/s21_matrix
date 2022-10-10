#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    if (rows <= 0 && columns <= 0) {
        return INCORRECT_MATRIX;
    } else if (rows > 0 && columns > 0) {
        result->rows = rows;
        result->columns = columns;
    }

        result->matrix = (double **) calloc(rows, sizeof(double *));
        if (result->matrix == NULL) {
            return INCORRECT_MATRIX;
        } else {
            for (int i = 0; i < rows; i++) {
                result->matrix[i] = (double *) calloc(columns, sizeof(double));
                if (!result->matrix[i]) {
                    for (int j = 0; j < i; j++)
                        free(result->matrix[j]);
                    free(result->matrix);

                    return INCORRECT_MATRIX;
                }
            }
        }
    return OK;
}

void s21_remove_matrix(matrix_t *A) {
    if (A->matrix != 0) {
        for (int row = 0; row < A->rows; row++)
            free(A->matrix[row]);
        free(A->matrix);
    }
}
