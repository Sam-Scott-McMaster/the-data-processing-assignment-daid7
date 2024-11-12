// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

float** clean_delete(float** array, int *rows, int cols) {
    // Create new 2D array, malloc by rows then each row by cols
    float** cleanArray = malloc((*rows) * sizeof(float *));
    for (int i = 0; i < *rows; i++) {
        cleanArray[i] = malloc((cols) * sizeof(float));
    }

    // Initialize valid rows counter and index
    int validRows = 0;

    // for each row
    for (int i = 0; i < *rows; i++) {

        // Declare boolean to check if row should be skipped due to nan
        bool skip = false;
        
        // check if nan in row
        for (int j = 0; j < cols; j++) {
            if (isnan(array[i][j]) != 0) {
                skip = true;
                break;
            }
        }

        // Check if skip
        if (skip == true) {
            continue;
        }

        // Append values from array to cleanArray if no nan
        for (int j = 0; j < cols; j++) {
            cleanArray[validRows][j] = array[i][j];
        }

        // Increment valid rows if valid row
        validRows += 1;
    }

    // update number of rows by side effect
    *rows = validRows;

    // Realloc memory to truncated number of rows
    cleanArray = realloc(cleanArray, (*rows) * sizeof(float *));

    // return cleaned array
    return cleanArray;
}