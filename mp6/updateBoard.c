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

    int x, y, live_cell_count=0;   //initialize x for rows, y for columns, and live_cell_count to keep track of alive cells
    //going to be using row major order
    //create loop to give x a value based on row
    for(x=row-1; x<= row; x++){
        if(x>=0 && x<=(boardRowSize-1)){
            //here comes loop for columns
            for(y=col-1; y<=col+1; y++){
                //look to lab6 matrix.c file and lab6 worksheet for how to convert and reference a 2-D matrix as a 1-D matrix
                //need to reference the matrix index's address/pointer
                if(*(board + x*boardColSize) == 1){     //(row index * column size) + column index
                    live_cell_count++;  //increase live cell counter by 1
                }
            }
        }
    }

////update the live cell counter --> update it to its current value live - value of (board pointer + row * boardColSize + col)
live_cell_count = live_cell_count - *(board + row*boardColSize + col);
return live_cell_count;    //give back latest live_cell_count

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
    int live_cell_count, x, y, new_board =[boardRowSize*boardColSize];   //create local live cell counter, x, and y variables again
    //initialize a new board array with same dimensions as original

    //new loop for x, starting from index 0
    for(x=0; x<=boardRowSize - 1; x++){
        //same deal for y, starting from index 0 too
        for(y=0; y<=boardColSize-1; y++){
            //here we gotta set the new board array equal to the pointer of the (OG board + x * boardColSize + y)
            new_board[x * boardColSize + y] = *(board + x * boardColSize + y);
        }
    }
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