/* Danny Dai, 400505160, 2024/11/21
 *
 * Reads a 2D grid of floats given int rows and columns length, and replace bad values with legal values,
 * either by imputation (replace by column average) or deletion (delete bad rows).
 * Then output the corrected 2D grid of floats data and updated rows and columns length.
 */

// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include self-defined functions
#include "read_data.h"
#include "clean_impute.h"
#include "clean_delete.h"
#include "output_data.h"

/* main
 *
 * Call read_data function to read 2D array, 
 * and get row and column length by side effect. 
 * Check command line arguments to call 
 * imputation or deletion function to replace bad values.
 * Call output_data to print row and column length, and 2D array.
 * Deallocate memory then exit program.
 */

int main(int argc, char *argv[]) {

    // Declare integers for rows and columns
    int rows = 0, cols = 0;

    // read 2D array, get rows and cols by side effect
    float** array = read_data(&rows, &cols);

    // Declare cleaned array
    float** cleanArray;

    // call Impute or Delete functions by command line arguments
    if (argc == 1) {
        cleanArray = clean_impute(array, rows, cols);
    }
    else if (argc == 2 && strcmp(argv[1], "-d") == 0) {
        cleanArray = clean_delete(array, &rows, cols); // rows may change
    }

    // print 2D array
    output_data(cleanArray, rows, cols);
    
    // deallocate array
    free(cleanArray);

    // Exit program
    return EXIT_SUCCESS;
}