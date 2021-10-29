#include "game.h"

/*
This game starts with user getting a random tile of value 2 or 4. The user then uses WSAD keys to move up, down, left, and right
repectively. This mimics the "2048" game with sliding tiles, so when 2 tiles of the same value who are horizontally/vertically adjacent
get swiped in the same direction, they fuse into one tile whose value is the sum of the previous 2 tiles
*/

game * make_game(int rows, int cols)
/*! Create an instance of a game structure with the given number of rows
    and columns, initializing elements to -1 and return a pointer
    to it. (See game.h for the specification for the game data structure) 
    The needed memory should be dynamically allocated with the malloc family
    of functions.
*/
{
    //Dynamically allocate memory for game and cells (DO NOT modify this)
    game * mygame = malloc(sizeof(game));
    mygame->cells = malloc(rows*cols*sizeof(cell));

    //YOUR CODE STARTS HERE:  Initialize all other variables in game struct
    int x = 0;  //initialize x

    for(x = 0; x<=((rows*cols)-1); x++){    //start from 0, then loop through to all cells
        *((*mygame).cells + x) = -1;    // set (a pointer points to a pointer plus x) equal to -1
    }

    //set row pointer equal to rows in mygame
    (*mygame).rows = rows;
    //set column pointer equal to column in mygame
    (*mygame).cols = cols;


    return mygame;
}

void remake_game(game ** _cur_game_ptr,int new_rows,int new_cols)
/*! Given a game structure that is passed by reference, change the
	game structure to have the given number of rows and columns. Initialize
	the score and all elements in the cells to -1. Make sure that any 
	memory previously allocated is not lost in this function.	
*/
{
	/*Frees dynamically allocated memory used by cells in previous game,
	 then dynamically allocates memory for cells in new game.  DO NOT MODIFY.*/
	free((*_cur_game_ptr)->cells);
	(*_cur_game_ptr)->cells = malloc(new_rows*new_cols*sizeof(cell));

	 //YOUR CODE STARTS HERE:  Re-initialize all other variables in game struct
     int x = 0;     // bring back x
     for(x = 0; x <= ((new_rows*new_cols)-1); x++){
         //re-initialize cells to -1
         //then take pointer to double pointer, add x,  and set to -1
         *((**_cur_game_ptr).cells + x) = -1;
     }
     //set new rows and columns in current game
     (**_cur_game_ptr).rows = new_rows;
     (**_cur_game_ptr).cols = new_cols;

	return;	
}

void destroy_game(game * cur_game)
/*! Deallocate any memory acquired with malloc associated with the given game instance.
    This includes any substructures the game data structure contains. Do not modify this function.*/
{
    free(cur_game->cells);
    free(cur_game);
    cur_game = NULL;
    return;
}

cell * get_cell(game * cur_game, int row, int col)
/*! Given a game, a row, and a column, return a pointer to the corresponding
    cell on the game. (See game.h for game data structure specification)
    This function should be handy for accessing game cells. Return NULL
	if the row and col coordinates do not exist.
*/
{
    //YOUR CODE STARTS HERE
    //current game needs to find row and column  to return the cell's next value to

    //check for valid row. Return NULL if row is out of bounds
    if(row < 0 || row >= (*cur_game).rows){
        return NULL;
    }

    //check for valid columns
    if(col < 0 || col >= (*cur_game).cols){
        return NULL;
    }

    return (*cur_game).cells + row * (*cur_game).cols + col;
    // return 
}

int move_w(game * cur_game)
/*!Slides all of the tiles in cur_game upwards. If a tile matches with the 
   one above it, the tiles are merged by adding their values together. When
   tiles merge, increase the score by the value of the new tile. A tile can 
   not merge twice in one turn. If sliding the tiles up does not cause any 
   cell to change value, w is an invalid move and return 0. Otherwise, return 1. 
*/
{
    //YOUR CODE STARTS HERE
    int x = 0;
    int y = 0;
    //re-initialize x and y
    int last_row = -1;
    int current_row = -1;
    int current_sum = 0;
    int holder = 0;

    //increment through y because we are moving in a vertically positive direction
    for(y = 0; y <= (*cur_game).cols - 1; y++){
        last_row = -1;

        //increment through rows now
        for(x = 0; x <= (*cur_game).rows - 1; x++){
            
            //make sure that the current_row is filled
            if(*((*cur_game).cells + x * (* cur_game).cols + y) != -1){
                current_sum = 0;

                //game needs to find current row to continue
                //need a for loop where current_row starts a 0 where condition is current_row<x and increments current_row
                for(current_row = 0; current_row < x; current_row++){
                    //here we need to check if pointer = -1
                    if(*((*cur_game).cells + current_row * (*cur_game).cols + y) == -1){
                        current_sum = 1;
                        break;      //exits program
                    }
                }

                //conditiional checck when current_sum=1
                if(current_sum == 1){
                    //then pointer from first part is set to pointer from second part
                     *((*cur_game).cells + current_row * (*cur_game).cols + y) = *((*cur_game).cells + x * (*cur_game).cols + y);

                     //then find out the current row's contents and allocate space
                     *((*cur_game).cells + x * (*cur_game).cols + y) = -1;
                     holder = 1;
                }

                //time for nested loops

                //check if (current_row - 1) != last_row
                if((current_row - 1) != last_row){
                    //
                    //if both results are the same
                    if(*((*cur_game).cells + (current_row - 1) * (*cur_game).cols + y) == *((*cur_game).cells + current_row * (*cur_game).cols + y)){
                        //
                        //row in front of current_row becomes the result doubled
                         *((*cur_game).cells + (current_row - 1) * (*cur_game).cols + y) *= 2;

                         //then update score
                         (*cur_game).score += *((*cur_game).cells + (current_row - 1) * (*cur_game).cols + y);

                         //then make sure that we don't have empty cells
                         *((*cur_game).cells + current_row * (*cur_game).cols + y) = -1;

                         //change last_row
                         last_row = current_row - 1;

                         //update holder
                         holder = 1;
                    }
                }
            }
        }
    }

    return holder;  // move_w will spit out holder
};

int move_s(game * cur_game) //slide down
{
    //YOUR CODE STARTS HERE
    int x = 0;
    int y = 0;
    //re-initialize x and y
    int last_row = -1;
    int current_row = -1;
    int current_sum = 0;
    int holder = 0;

    //reset last_row to -1
    for(y = 0; y <= (*cur_game).cols -1; y++){
        last_row = -1;
    }

    //nested for loop time
    //check if current_row is empty
    for(x = (*cur_game).rows -1; x >= 0; x--){
        //
        if(*((*cur_game).cells + x * (*cur_game).cols + y) != -1){
            current_sum = 0;

            //another loop to find current solution
            for(current_row = (*cur_game).rows -1; current_row > x; current_row--){
                if(*((*cur_game).cells + current_row * (*cur_game).cols + y) == -1){
                    current_sum = 1;
                    break;
                }
            }

            //another if loop but for current_sum == 1
            if(current_sum == 1){
                //
                *((*cur_game).cells + current_row * (*cur_game).cols + y) = *((*cur_game).cells + x * (*cur_game).cols + y);

                //clear contents of row
                *((*cur_game).cells + x * (*cur_game).cols + y) = -1;

                holder = 1;
            }

            //more nested if's
            if((current_row + 1) != last_row){
                //conditional if d-reference of pointers are the same
                if(*((*cur_game).cells + (current_row + 1) * (*cur_game).cols + y) == *((*cur_game).cells + current_row * (*cur_game).cols + y)){
                    //
                    *((*cur_game).cells + (current_row + 1) * (*cur_game).cols + y) *= 2;

                    (*cur_game).score += *((*cur_game).cells + (current_row + 1) * (*cur_game).cols + y);

                    *((*cur_game).cells + current_row * (*cur_game).cols + y) = -1;

                    last_row = current_row + 1;

                    holder = 1;
                }
            }
        }
    }

    return holder;
};

int move_a(game * cur_game) //slide left
{
    //YOUR CODE STARTS HERE
    int x = 0;
    int y = 0;
    //re-initialize x and y
    int last_column = -1;   //  use column instead of row for move_a and move_d
    int current_column = -1;
    int current_sum = 0;
    int holder = 0;

    //rinse and repeat loops and conditionals
    for(x = 0; x <= (*cur_game).rows - 1; x++){
        last_column = -1;

        for(y = 0; y <= (*cur_game).cols - 1; y++){
            //
            if(*((*cur_game).cells + x * (*cur_game).cols + y) != -1){
                current_sum = 0;

                for(current_column = 0; current_column < y; current_column++){
                    //
                    if(*((*cur_game).cells + x * (*cur_game).cols + current_column) == -1){
                        current_sum = 1;
                        break;
                    }
                }

                //rinse and repeat
                if(current_sum == 1){
                    //
                    *((*cur_game).cells + x * (*cur_game).cols + current_column) = *((*cur_game).cells + x * (*cur_game).cols + y);

                    *((*cur_game).cells + x * (*cur_game).cols + y) = -1;

                    holder = 1;
                 }

                 if((current_column - 1) != last_column){
                    //
                    if(*((*cur_game).cells + x * (*cur_game).cols + (current_column - 1)) == *((*cur_game).cells + x * (*cur_game).cols + current_column)){
                        //
                        *((*cur_game).cells + x * (*cur_game).cols + (current_column - 1)) *= 2;

                        (*cur_game).score += *((*cur_game).cells + x * (*cur_game).cols + (current_column - 1));

                        *((*cur_game).cells + x * (*cur_game).cols + current_column) = -1;

                        holder = 1;
                    }
                 }
            }
        }
    }

    return holder;
};

int move_d(game * cur_game){ //slide to the right
    //YOUR CODE STARTS HERE
    int x = 0;
    int y = 0;
    //re-initialize x and y
    int last_column = -1;   //  use column instead of row for move_a and move_d
    int current_column = -1;
    int current_sum = 0;
    int holder = 0;

    //rinse and repeat loops and conditionals
    for(x = 0; x <= (*cur_game).rows - 1; x++){
        last_column = -1;

        for(y = (*cur_game).cols - 1; y >= 0; y--){
            //
            if(*((*cur_game).cells + x * (*cur_game).cols + y) != -1){
                current_sum = 0;

                for(current_column = (*cur_game).cols - 1; current_column >= y; current_column--){
                    //
                    if(*((*cur_game).cells + x * (*cur_game).cols + current_column) == -1){
                        current_sum = 1;
                        break;
                    }
                }

                //rinse and repeat
                if(current_sum == 1){
                    //
                    *((*cur_game).cells + x * (*cur_game).cols + current_column) = *((*cur_game).cells + x * (*cur_game).cols + y);

                    *((*cur_game).cells + x * (* cur_game).cols + y) = -1;

                    holder = 1;
                 }

                 if((current_column + 1) != last_column){
                    //
                    if(*((*cur_game).cells + x * (*cur_game).cols + (current_column + 1)) == *((*cur_game).cells + x * (*cur_game).cols + current_column)){
                        //
                        *((*cur_game).cells + x * (*cur_game).cols + (current_column + 1)) *= 2;

                        (*cur_game).score += *((*cur_game).cells + x * (*cur_game).cols + (current_column + 1));

                        *((*cur_game).cells + x * (*cur_game).cols + current_column) = -1;

                        last_column = current_column - 1;

                        holder = 1;
                    }
                 }
            }
        }
    }

    return holder;
};

int legal_move_check(game * cur_game)
/*! Given the current game check if there are any legal moves on the board. There are
    no legal moves if sliding in any direction will not cause the game to change.
	Return 1 if there are possible legal moves, 0 if there are none.
 */
{
    //YOUR CODE STARTS HERE
    game * copy_game = make_game((*cur_game).rows, (*cur_game).cols);      //copy same game

    int end_move = 0;
    int x;     //   can't go wrong with classics

    for(x = 0; x <= (((*cur_game).rows * (*cur_game).cols) - 1); x++){
        //
        *((*copy_game).cells + x) = *((*cur_game).cells + x);
    }

    //check for movement in cells
    if((move_w(copy_game) + move_a(copy_game) + move_s(copy_game) + move_d(copy_game)) != 0){
        //
        end_move = 1;
    }


    return end_move;
}


/*! code below is provided and should not be changed */

void rand_new_tile(game * cur_game)
/*! insert a new tile into a random empty cell. First call rand()%(rows*cols) to get a random value between 0 and (rows*cols)-1.
*/
{
	
	cell * cell_ptr;
    cell_ptr = 	cur_game->cells;
	
    if (cell_ptr == NULL){ 	
        printf("Bad Cell Pointer.\n");
        exit(0);
    }
	
	
	//check for an empty cell
	int emptycheck = 0;
	int i;
	
	for(i = 0; i < ((cur_game->rows)*(cur_game->cols)); i++){
		if ((*cell_ptr) == -1){
				emptycheck = 1;
				break;
		}		
        cell_ptr += 1;
	}
	if (emptycheck == 0){
		printf("Error: Trying to insert into no a board with no empty cell. The function rand_new_tile() should only be called after tiles have succesfully moved, meaning there should be at least 1 open spot.\n");
		exit(0);
	}
	
    int ind,row,col;
	int num;
    do{
		ind = rand()%((cur_game->rows)*(cur_game->cols));
		col = ind%(cur_game->cols);
		row = ind/cur_game->cols;
    } while ( *get_cell(cur_game, row, col) != -1);
        //*get_cell(cur_game, row, col) = 2;
	num = rand()%20;
	if(num <= 1){
		*get_cell(cur_game, row, col) = 4; // 1/10th chance
	}
	else{
		*get_cell(cur_game, row, col) = 2;// 9/10th chance
	}
}

int print_game(game * cur_game) 
{
    cell * cell_ptr;
    cell_ptr = 	cur_game->cells;

    int rows = cur_game->rows;
    int cols = cur_game->cols;
    int i,j;
	
	printf("\n\n\nscore:%d\n",cur_game->score); 
	
	
	printf("\u2554"); // topleft box char
	for(i = 0; i < cols*5;i++)
		printf("\u2550"); // top box char
	printf("\u2557\n"); //top right char 
	
	
    for(i = 0; i < rows; i++){
		printf("\u2551"); // side box char
        for(j = 0; j < cols; j++){
            if ((*cell_ptr) == -1 ) { //print asterisks
                printf(" **  "); 
            }
            else {
                switch( *cell_ptr ){ //print colored text
                    case 2:
                        printf("\x1b[1;31m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 4:
                        printf("\x1b[1;32m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 8:
                        printf("\x1b[1;33m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 16:
                        printf("\x1b[1;34m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 32:
                        printf("\x1b[1;35m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 64:
                        printf("\x1b[1;36m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 128:
                        printf("\x1b[31m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 256:
                        printf("\x1b[32m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 512:
                        printf("\x1b[33m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 1024:
                        printf("\x1b[34m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 2048:
                        printf("\x1b[35m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 4096:
                        printf("\x1b[36m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 8192:
                        printf("\x1b[31m%04d\x1b[0m ",(*cell_ptr));
                        break;
					default:
						printf("  X  ");

                }

            }
            cell_ptr++;
        }
	printf("\u2551\n"); //print right wall and newline
    }
	
	printf("\u255A"); // print bottom left char
	for(i = 0; i < cols*5;i++)
		printf("\u2550"); // bottom char
	printf("\u255D\n"); //bottom right char
	
    return 0;
}

int process_turn(const char input_char, game* cur_game) //returns 1 if legal move is possible after input is processed
{ 
	int rows,cols;
	char buf[200];
	char garbage[2];
    int move_success = 0;
	
    switch ( input_char ) {
    case 'w':
        move_success = move_w(cur_game);
        break;
    case 'a':
        move_success = move_a(cur_game);
        break;
    case 's':
        move_success = move_s(cur_game);
        break;
    case 'd':
        move_success = move_d(cur_game);
        break;
    case 'q':
        destroy_game(cur_game);
        printf("\nQuitting..\n");
        return 0;
        break;
	case 'n':
		//get row and col input for new game
		dim_prompt: printf("NEW GAME: Enter dimensions (rows columns):");
		while (NULL == fgets(buf,200,stdin)) {
			printf("\nProgram Terminated.\n");
			return 0;
		}
		
		if (2 != sscanf(buf,"%d%d%1s",&rows,&cols,garbage) ||
		rows < 0 || cols < 0){
			printf("Invalid dimensions.\n");
			goto dim_prompt;
		} 
		
		remake_game(&cur_game,rows,cols);
		
		move_success = 1;
		
    default: //any other input
        printf("Invalid Input. Valid inputs are: w, a, s, d, q, n.\n");
    }

	
	
	
    if(move_success == 1){ //if movement happened, insert new tile and print the game.
         rand_new_tile(cur_game); 
		 print_game(cur_game);
    } 

    if( legal_move_check(cur_game) == 0){  //check if the newly spawned tile results in game over.
        printf("Game Over!\n");
        return 0;
    }
    return 1;
}
