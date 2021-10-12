/*
This MP is about "The Game of Life" - also called "Life". It is a "cellular automaton" invented by British mathematician John Horton Conway in 1970". In the game, the "universe" is a two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead. Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1)	Any live cell with fewer than two live neighbours dies, as if caused by under-population.
2)	Any live cell with two or three live neighbours lives on to the next generation.
3)	Any live cell with more than three live neighbours dies, as if by over-population.
3)	Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

The initial pattern is called the "seed" of the system. The game board is composed of "cells" which will be represented here by a matrix, where 0 is a dead cell and 1 is an alive cell. The rules will apply to every cell in the system simultaneously in every iteration. In this MP, the game board will be represented as a 1-D array. The size of the array is Width*Height. The game board will be passed as pointer (for example int *game_board). For example, to access the 10th element of the array, use the syntax "game_board[9]" (without the quotes, and remember that index starts from 0).
*/

/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
}
/*
 * Update the game board to the next step.
 * Input: 
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {
}

/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with 
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */ 
int aliveStable(int* board, int boardRowSize, int boardColSize){
}

				
				
			

