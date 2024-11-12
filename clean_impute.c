// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* clean_impute
 * 
 * Parameters:  float** array = 2D array, 
 *              int rows = number of rows in 2D array, 
 *              int cols = number of columns in 2D array.
 * Purpose:     Replace bad values by its column's valid values' average, 
 *              replace by 0 if none valid in column, return cleaned array.
 * Outputs:     None
 * Returns:     float** array = modified 2D array replaced bad values
 */

float** clean_impute(float** array, int rows, int cols) {

    // Declare averages array
    float *averages = malloc(cols * sizeof(float));

    // Initialize averages as zeroes
    for (int i = 0; i < cols; i++) {
        averages[i] = 0;
    }

    // Get average for each column
    for (int i = 0; i < cols; i++) {

        // Initialize valid columns counter
        float valid = 0.0;

        // for each row
        for (int j = 0; j < rows; j++) {
            // if not nan, add value
            if (isnan(array[j][i]) == 0) {
                averages[i] += array[j][i];
                valid += 1.0;
            }
        }

        // divide average by number of valid numbers, if any
        if (valid > 1) {
            averages[i] /= valid;
        }
    }

    // Replace nan by average at its column
    for (int i = 0; i < cols; i++) {
        // for each row
        for (int j = 0; j < rows; j++) {
            // if nan, change to average at column
            if (isnan(array[j][i]) != 0) {
                array[j][i] = averages[i];
            }
        }
    }

    // deallocate
    free(averages);

    // Return 2D array
    return array;
}