// Include standard libraries
#include <stdio.h>
#include <stdlib.h>

/* output_data
 * 
 * Parameters:  float** array = cleaned 2D array, 
 *              int rows = number of rows in 2D array,
 *              int cols = number of columns in 2D array.
 * Purpose:     print rows and columns length separated by space,
 *              then print 2D array a row in each line, columns separated by space.
 * Outputs:     rows and column length, 2D array -> stdout
 * Returns:     None
 */

void output_data(float** array, int rows, int cols) {
    // Print row and columns length
    printf("%d %d\n", rows, cols);

    // Print each row
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%.3f ",array[r][c]);
        }
        puts("");
    }
}