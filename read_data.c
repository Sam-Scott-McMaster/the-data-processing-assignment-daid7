// Include standard libraries
#include <stdio.h>
#include <stdlib.h>

/* read_data
 * 
 * Parameters:  int *rows = number of rows in 2D array, allow side effect,
 *              int *cols = number of columns in 2D array, allow side effect.
 * Purpose:     read rows and columns length, declare 2D array by row and column length,
 *              allocate memory for 2D array, read 2D array data, return 2D array.
 * Outputs:     None
 * Returns:     float** array = 2D array read from data
 */

float** read_data(int *rows, int *cols) {

    // Get rows and cols, and return back by side effect
    scanf("%d", &(*rows));
    scanf("%d", &(*cols));

    // Declare 2D array, malloc by length of rows, 
    // then for each row malloc column length
    float** array = malloc((*rows) * sizeof(float *));
    for (int i = 0; i < *rows; i++) {
        array[i] = malloc((*cols) * sizeof(float));
    }

    // Get data 
    for (int r = 0; r < *rows; r++) {
        for (int c = 0; c < *cols; c++) {
            scanf("%f", &array[r][c]);
        }
    }

    // return 2D array
    return array;

}
