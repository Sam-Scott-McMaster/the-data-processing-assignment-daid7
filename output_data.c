// Include standard libraries
#include <stdio.h>
#include <stdlib.h>

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