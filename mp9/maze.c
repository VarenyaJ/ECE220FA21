#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

/*
The goal of this MP is to implement a maze solver using a recursive depth-first search, as well as a couple of
functions that can be used to verify a correct solution. The maze output is the same as the initial width and height
of the input maze. The program uses "%" to denote a wall, whereas an empty cell/path is left as a blank space.
The input program also dictates where the start and endpoints are by "S" and "E" characters respectively.
*/


/*
 * createMaze -- Creates and fills a maze structure from the given file
 * INPUTS:       fileName - character array containing the name of the maze file
 * OUTPUTS:      None 
 * RETURN:       A filled maze structure that represents the contents of the input file
 * SIDE EFFECTS: None
 */
maze_t * createMaze(char * fileName)
{
    // Your code here. Make sure to replace following line with your own code.
    return NULL;
}

/*
 * destroyMaze -- Frees all memory associated with the maze structure, including the structure itself
 * INPUTS:        maze -- pointer to maze structure that contains all necessary information 
 * OUTPUTS:       None
 * RETURN:        None
 * SIDE EFFECTS:  All memory that has been allocated for the maze is freed
 */
void destroyMaze(maze_t * maze)
{
    // Your code here.
    int i;
    //for loop which access all the mallocs in createMaze and frees them
    for (i = 0; i < maze->height; i++){
        free(maze->cells[i]);   //frees data inside cells
        free(maze->cells);      //frees all cells
        free(maze);             //free maze
        maze = NULL;            //make sure maze does not point anywhere
    }
}

/*
 * printMaze --  Prints out the maze in a human readable format (should look like examples)
 * INPUTS:       maze -- pointer to maze structure that contains all necessary information 
 *               width -- width of the maze
 *               height -- height of the maze
 * OUTPUTS:      None
 * RETURN:       None
 * SIDE EFFECTS: Prints the maze to the console
 */
void printMaze(maze_t * maze)
{
    // Your code here.
    int i, j;
    printf("%d %d\n", maze -> width, maze -> height);   // print out maze width and height
    //                                                  // nested for loops
    for (i = 0; i < maze -> height; i++){               // if i/j is less than the data reference to the maze and its height/width 
      for (j = 0; j < maze -> width; j++){              // i/j will move through the iterations
        printf("%c", maze -> cells[i][j]);              // print while maze data is set to the current array value at i and j
      }
      printf("\n");                                         //print a newline after each row
    }
}

/*
 * solveMazeManhattanDFS -- recursively solves the maze using depth first search,
 * INPUTS:               maze -- pointer to maze structure with all necessary maze information
 *                       col -- the column of the cell currently beinging visited within the maze
 *                       row -- the row of the cell currently being visited within the maze
 * OUTPUTS:              None
 * RETURNS:              0 if the maze is unsolvable, 1 if it is solved
 * SIDE EFFECTS:         Marks maze cells as visited or part of the solution path
 */ 
int solveMazeDFS(maze_t * maze, int col, int row)
{
    // Your code here. Make sure to replace following line with your own code.
    return 0;
}