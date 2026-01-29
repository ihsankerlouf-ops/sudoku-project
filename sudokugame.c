>
int main() {
    int grid[9][9];
    int i, j, num;
    int row, col;
    int found = 1#include <std;
io.h

    /* Read the Sudoku grid (0 represents empty cells) */
    printf("Enter the Sudoku grid (use 0 for empty cells):\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    /* Try to solve the Sudoku */
    while (found) {
        found = 0;

        /* Loop through each cell */
        for (row = 0; row < 9; row++) {
            for (col = 0; col < 9; col++) {

                /* If the cell is empty */
                if (grid[row][col] == 0) {

                    /* Try numbers from 1 to 9 */
                    for (num = 1; num <= 9; num++) {
                        int valid = 1;

                        /* Check if the number already exists in the row or column */
                        for (i = 0; i < 9; i++) {
                            if (grid[row][i] == num || grid[i][col] == num) {
                                valid = 0;
                                break;
                            }
                        }

                        /* Check the 3x3 subgrid */
                        int startRow = (row / 3) * 3;
                        int startCol = (col / 3) * 3;
                        for (i = startRow; i < startRow + 3; i++) {
                            for (j = startCol; j < startCol + 3; j++) {
                                if (grid[i][j] == num) {
                                    valid = 0;
                                }
                            }
                        }

                        /* If the number is valid, place it in the cell */
                        if (valid) {
                            grid[row][col] = num;
                            found = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    /* Pri*
