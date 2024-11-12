// Include standard libraries
#include <stdio.h>
#include <stdlib.h>

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

    // Initialize 
    for (int r = 0; r < *rows; r++) {
        for (int c = 0; c < *cols; c++) {
            scanf("%f", &array[r][c]);
        }
    }

    // return 2D array
    return array;

}
