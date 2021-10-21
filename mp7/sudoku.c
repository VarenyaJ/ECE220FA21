#include "sudoku.h"

//-------------------------------------------------------------------------------------------------
// Start here to work on your MP7
//-------------------------------------------------------------------------------------------------

/*
This program solves a Sudoku puzzle recursively using backtracking. Number 1-9 are used to fill the 9x9 grid, with no repeats in
the same row, column, or 3x3 grid. We go down each row or column and try to fill in the empty cells, which have value 0
*/

// You are free to declare any private functions if needed.

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
  int y;    //variable to track columns in the row function

  //for loop to increment the column tracker
  for(y = 0; y <= 8; y++){
      //
      //check if int val is the same as the value in the sudoku array's current column
      if(val == sudoku[i][y]){
          return 1;
      }
  }
  
  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);

  // BEG TODO
  int x;    //variable to track rows in the column function

  //for loop to increment the row tracker
  for(x = 0; x <= 8; x++){
      //
      //check if int val is the same as the value in the sudoku array's current row
      if(val == sudoku[x][j]){
          return 1;
      }
  }
  
  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
  assert(i>=0 && i<9);
  
  // BEG TODO
  int x, y;     //bring back row and column trackers
  int partial_x = 3 * int(i / 3);    // break 9x9 grid into 3x3 grid
  int partial_y = 3 * int(j / 3);    // then check if val is in the 3x3 grid

  //assign x the current value of partial_x
  for(x = partial_x; x <= partial_x + 2; x++){
      //another loop after accesing row
      for (y = partial_y; y <= partial_y + 2; y++){
          //
          //check if val is the same as the current value at sudoku[x][y]
          if(val == sudoku[x][y]){
              return 1;
          }
      }
      
  }
  


  return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  // BEG TODO
  //
  //if any of the previous functions return 1, then <valid> should return a 0
  if(is_val_in_row(val, i, sudoku) == 1 || is_val_in_col(val, j, sudoku) == 1 || is_val_in_3x3_zone(val, i, j, sudoku) ==1 ){
      //
      return 0;
  }
    //  else return 1
  return 1;
  // END TODO
}

//  create new extra function
int check_if_hold_value(int sudoku[9][9]){
    //
    int i, j;   //bring back i and j

    for(i = 0; i <= 8; i++){
        //
        for(j = 0; j <= 8; j++){
            //  check if the cell's value if 0
            if(sudoku[i][j] == 0){
                return 0;
            }
        }
    }

    return 1;   // else return 1 if the cell has a valid number inside
}


//


// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {

  // BEG TODO.
  int i, j, x, y, num_count;    // need to bring back x and y, row and column counters, and a new variable, num_count
  if (check_if_hold_value(sudoku) == 1){
      return 1;
  }

  else{
      //
      for(i = 0; i <= 8; i++){
        //
        for(j = 0; j <= 8; j++){
            //  check if the cell's value if 0
            if(sudoku[i][j] == 0){
                x = i;
                y = j;
                i = 9;
                j = 9;
            }
        }
    }
  }


  //    a for loop which uses a new variable to increment thought and then call is_val_valid    -   new variable is num_count
  for(num_count = 1; num_count <= 9; num_count++){
      //
      if(is_val_valid(num_count, x, y, sudoku) == 1){
          // then the sudoku array at x, y is set to count_num's current value
          sudoku[x][y] = num_count;


          if(solve_sudoku(sudoku) == 1){
              //
              return 1;
          }

          sudoku[x][y] = 0;     //set sudoku at x,y = 0
      }
  }

  return 0;
  // END TODO.
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}




