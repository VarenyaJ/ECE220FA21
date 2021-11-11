#include "sparsemat.h"

#include <stdio.h>
#include <stdlib.h>

/*
This program  sues a data structure called a "list of tuples" that stores sparse matrices more
efficiently than a 2-D array (a sparse matrixis mostly comprised of elements of 0).

We store only non-zero elements in a list of rows. This program should be able to add 2 matricies,
return the value at a certain row/column index, etc.

We read the file describing matrix dimensions and element values. In set_tuples,
we check if the matrix is empty. If empty, we create a node and use it as a head, and if not,
we remove/ignore the node. For non-zero values, we create a new node and point it to the right location,
or just update a previous node.	
*/


//From MP10 (https://wiki.illinois.edu/wiki/display/ece220/FA21+MP10+-+Sparse+Matrix): 
//The elements in the input text file may be unordered (unlike the example text file above),
//but the list of tuples returned will need to be in order.


//read input file and produce matrix
sp_tuples * load_tuples(char* input_file)
{
    int row_count, int col_count;   //initialize row and column variables
    sp_tuples *jump = (sp_tuples*)malloc(sizeof(sp_tuples));  //new tuple to hold matrix, with pointer jump
    //open input file, read contents, put them in new matrix
    FILE *fjump = fopen(input_file, "r");
    //scan in two elements to address of row and colum variables
    fscanf(fjump, "%d %d\n", &r, &c); 

	series->m = row_count;  //set # of rows to r	
	series->n = col_count;  //set # of columns to c
	series->nz = 0;         //initialize number of nonzero elements to 0
	series->tuples_head = NULL; //initialize head pointer to NULL


    int i, j;   //variables to fill in indecies
    double k;   //jump through positions

    while ((fscanf(fjump, "%d %d %lf\n", &i, &j, &k) == 3)
    {
        //call set_tuples to full in position with values adjacent
        set_tuples(jump, i, j, k)
    }

    if(!feof(fjump)){   //use feof to detect end of file stream
        return NULL;
    }

    fclose(fjump);  //close file
    return jump;

}



double gv_tuples(sp_tuples * mat_t,int row,int col)

{
    //
    return 0;
}



void set_tuples(sp_tuples * mat_t, int row, int col, double value)
{
    //
    return;
}



void save_tuples(char * file_name, sp_tuples * mat_t)
{

	return;
}



sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB){

	return retmat;
}



sp_tuples * mult_tuples(sp_tuples * matA, sp_tuples * matB){ 
    return retmat;

}


	
void destroy_tuples(sp_tuples * mat_t){
	
    return;
}  






