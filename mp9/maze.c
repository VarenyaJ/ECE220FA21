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
    int i, j, row_count, col_count;     //initialize i and j to count index, then use row_count and col_count to go through cells
    char c;     //create new character value

    FILE *reader = fopen(fileName, "r");    //use file with pointer reader to create a stream which can map the maze
    fscanf(reader, "%d %d", &col_count, &row_count);    //read the column and row data from the file
    maze_t *new_maze = malloc(sizeof(maze_t));   //allocate memory for the maze_t structure

    new_maze -> height = row_count;     //structure for the rows
    new_maze -> width = col_count;      ////structure for the columns
    
    new_maze -> cells = (char **)malloc(row_count * sizeof(char *));  //allocate memory for the cells within the program
    
    //this for loop goes through the allocation structure and allows data from memory to be written to the program
    //this way, when i=0 && i<row_count, the loop iterates through the cells and increments i
    for (i = 0; i < row_count; i++){
        new_maze -> cells[i] = (char *)malloc(col_count * sizeof(char));
    }

    //another set of nested loops accesses the row and columns in order to coy the maze onto the program file
    for (i = 0; i < row_count; i++){
        for (j = 0; j < col_count; j++){
            c = fgetc(reader);      // copy/duplicate the maze into the file here

            //conditional statement to map how to iterate through loops
            //if mae is not equal to newline character, then the duplication maze value is set to the currect value of c
            if(c != '/n'){
                new_maze -> cells[i][j] = c;
            }
            else{   //if it is equal to the newline character, then we don't save the data, we just loop through the iteration
                j--;
            }

            //another nested conditional if the column variable is >= 0
            if(j >= 0){     //access cell[i][-1]
                if(new_maze -> cells[i][j] == START){
                    //starting point
                    //record the start point
                    new_maze -> startRow = i;
                    new_maze -> startColumn = j;
                }
                
                //access and record the endpoint of the program through the maze data
                if(new_maze -> cells[i][j] == END){
                    new_maze -> endRow = i;
                    new_maze -> endColumn = j;
                }
            }

        }
    }

    fclose(reader);     //close the file stream    
    
    return new_maze;
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