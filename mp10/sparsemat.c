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


//  need to pass in arguements from gv_tuples 
int sort_tuples(sp_tuples_node *locus1, sp_tuples_node *locus2){
    //compare row elements of locus1 and locus2
	if((locus1->row) != (locus2->row)){
	//if not equal, return 1 if locus1’s row element >= locus2’s row element
    //return 0 if locus1’s row element <= locus2’s row element
	return ( (locus1->row) > (locus2->row)) ; 
	}
    
	//if row elements are equal, check columns
    //Return 1 if locus1’s column element > locus2’s column element
    //Return 0 otherwise
	else{
	
	   return ( (locus1->col) > (locus2->col) );
	}
}   // treat return quantity as boolean


//read input file and produce matrix
sp_tuples * load_tuples(char* input_file)
{
    int row_count;
    int col_count;   //initialize row and column variables
    sp_tuples *jump = (sp_tuples*)malloc(sizeof(sp_tuples));  //new tuple to hold matrix, with pointer jump
    //open input file, read contents, put them in new matrix
    FILE *fjump = fopen(input_file, "r");
    //scan in two elements to address of row and colum variables
    fscanf(fjump, "%d %d\n", &row_count, &col_count); 

	jump->m = row_count;  //set # of rows to row_count	
	jump->n = col_count;  //set # of columns to col_count
	jump->nz = 0;         //initialize number of nonzero elements to 0
	jump->tuples_head = NULL; //initialize head pointer to NULL


    int i, j;   //variables to fill in indecies
    double k;   //jump through positions

    while ((fscanf(fjump, "%d %d %lf\n", &i, &j, &k) == 3))
    {
        //call set_tuples to full in position with values adjacent
        set_tuples(jump, i, j, k);
    }

    if(!feof(fjump)){   //use feof to detect end of file stream
        return NULL;
    }

    fclose(fjump);  //close file
    return jump;

}



double gv_tuples(sp_tuples * mat_t,int row,int col)
{
    //make 'locus' point to the same location as the head ptr of the inout matrix tuple
    sp_tuples_node *locus = mat_t->tuples_head;

    //while conditional: while locus is not NULL, go through tuple pointed by 'locus' until program reaches
    //last value
    while (locus != NULL)
    {
        if(locus->row == row && locus->col == col){
            return locus->value;
        }

        //locus is set to the locus with elements in next, moving on
        locus = locus->next;
    }

    return 0;   //return 0 if the right locus value is not returned
}



void set_tuples(sp_tuples * mat_t, int row, int col, double value)
{
    //conditional if the matrix with elements in the tuples head is NULL
    if(mat_t->tuples_head == NULL){
        //if the value is not 0
        if(value != 0){
            
            //allocate space for a new locus node
            sp_tuples_node *locus2 = (sp_tuples_node*)malloc(sizeof(sp_tuples_node));

            //get contents of new node and set them equal to arguements passed into set_tuples
            locus2->row = row; //set # of rows to row
            locus2->col = col; //set # of columns to col
            locus2->value = value; //set locus2 with elements in value to value
            locus2->next = NULL; //make locus with elements in next equal to NULL

            //matrix with tuples head set to new node
            mat_t->tuples_head = locus2;
            mat_t->nz++; //increment the number of non-zero elements
        }
        return;
    }

    //nested conditionals and loops
    if(gv_tuples(mat_t, row, col) != 0){
        //if value is 0, continue to delete locus value
        if(value == 0){
            sp_tuples_node *reverse = NULL;
	        sp_tuples_node *locus = mat_t->tuples_head;

            while (locus != NULL)
            {
                if(locus->row == row && locus->col == col){
                    //if reverse is NULL, program deletes the locus node and set the new locus vaue to the next node
                    if(reverse == NULL){
                        //set matrix with elements in tuples head to the next locus
                        mat_t->tuples_head = locus->next;
                    }
                    
                    //if the locus exists but is non-zero, update the locus node to the current value
                    else{
                        //reverse locus set to next locus
                        reverse->next = locus->next;
                    }

                    free(locus);    //free locus node
                    mat_t->nz--;    //decrement for a non-zero entry in matrix 

                    return;
                }

                reverse = locus;
                locus = locus->next;
            }
        }

        //update locus
        else
        {
            //update locus node with matrix head element
            sp_tuples_node *locus = mat_t->tuples_head;

            while (locus != NULL)
            {
                if(locus->row == row && locus->col == col){
                    locus->value = value;
                    return;
                }

                locus = locus->next;    //set locus to next locus
            }
            
        }
    }

    else{
        //if locus node does not exist and the value at locus is 0
        if(value == 0){
            //if element of 0 is added to matrix
            return;
        }

        //else add mode to locus node
        else{
            sp_tuples_node *reverse = NULL; //reverse node returns as NULL
            sp_tuples_node *locus = mat_t->tuples_head; //locus node becomes matrix with elements in head

            //need to copy new pointer file reference
            sp_tuples_node *copy = (sp_tuples_node*)malloc(sizeof(sp_tuples_node));
            copy->row = row;    //row element of copy is set to row
            copy->col = col;    //col element of copy is set to col
            copy->value = value;    //value element of copy is set to value
            copy->next = NULL;      //”next” element of copy is set to NULL

            mat_t->nz++;    //increment for non-zero matrix element

            while (locus != NULL)
            {
                //if locus node is after copy pointer
                if(sort_tuples(locus, copy)){
                    //going to replace locus
                    if(reverse == NULL){
                        copy->next = locus;
                        mat_t->tuples_head = copy;
                    }
                    
                    //else insert the value between the locus nodes
                    else{
                        reverse->next = copy;   //reverse pointing to next is set to copy
                        copy->next = locus;     //copy pointing to next is set to locus
                    }
                    return;
                }

                reverse = locus;
                locus = locus->next;
            }
            //allocate new locus node to the end
            reverse->next = copy;
            return;
        }
    }

    return;
}



void save_tuples(char * file_name, sp_tuples * mat_t)
{
FILE* fjump = fopen(file_name, "w"); //opens file_name to begin writing into it
	
	fprintf(fjump, "%d %d\n", mat_t->m, mat_t->n); //print mat_t row elements m and n
	
	sp_tuples_node* locus = mat_t->tuples_head; //node variable is set to matrix with head elements
	
	while(locus != NULL){ //while the variable does not equal null
	
	//print string with variables containing row, column, and value elements
	fprintf(fjump, "%d %d %lf\n", locus->row, locus->col, locus->value);

	locus = locus->next; //variable becomes var with elements held in next/point to next variable
	}
	
	fclose(fjump); //close fjump stream
	
	return; //return
}



sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB){
    //allocate space for a new matrix called 'retmat'
    //initialize retmat
    //needs to have dimensions m and n
    //set retman equal to matrix A with dimensions m and n
    sp_tuples *retmat = (sp_tuples*)malloc(sizeof(sp_tuples));

    retmat->m = matA->m;        //the row element of retmat is set equal to the row element of matA
    retmat->n = matA->n;        //the column element of retmat is set equal to the column element of matA
    retmat->nz = 0;             //non-zero elements in matrix are set equal to 0
    retmat->tuples_head = NULL; //the matrix with head is set to null

    //create new nodes to traverse from locusA and locusB
    sp_tuples_node *locusA = matA->tuples_head;
    sp_tuples_node *locusB = matB->tuples_head;

    while (locusA != NULL)
    {
        //set values of remat matrix to the values of locusA matrix
        set_tuples(retmat, locusA->row, locusA->col, locusA->value);

        locusA = locusA->next;  //locusA is set to locusA with elements in next
    }

    while (locusB != NULL)
    {
        //create a double value and set it equal to the gv_tuples function
        double copy_gv = gv_tuples(retmat, locusB->row, locusB->col);
        //call set_tuples
        set_tuples(retmat, locusB->row, locusB->col, locusB->value + copy_gv);

        locusB = locusB->next;  //set locusB to itself with next elements
    }

	return retmat;
}



sp_tuples * mult_tuples(sp_tuples * matA, sp_tuples * matB){


    if(matA->n != matB->m){
        //if the matricies are not equal to nxm dimensions
        return NULL;
    }

    sp_tuples *retmat = (sp_tuples*)malloc(sizeof(sp_tuples)); //allocate and reinitialize retmat
    retmat->m = matA->m; //set retmat with dimension m to matrix A with dimension m
    retmat->n = matB->n; //set retmat with dimension n to matrix B with dimension n
    retmat->nz = 0; //non-zero matrix element of 0
    retmat->tuples_head = NULL; //the head matrix is NULL


    sp_tuples_node *locusA = matA->tuples_head; //traverse matrix locusA
    while (locusA != NULL)
    {
        int x_of_A = locusA->row; //initialize a new variable and set it equal to locusaA with elements in row
        int y_of_A = locusA->col; //initialize a new variable and set it equal to locusaA with elements in col

        sp_tuples_node *locusB = matB->tuples_head; //traverse matrix locusB
        while (locusB != NULL){
            int x_of_B = locusA->row; //initialize a new variable and set it equal to locusaA with elements in row
            int y_of_B = locusA->col; //initialize a new variable and set it equal to locusaA with elements in col

            //if row of b = col of a
            if(x_of_B == y_of_A){
                double value_at_A = gv_tuples(matA, x_of_A, y_of_A);
                double value_at_B = gv_tuples(matB, x_of_B, y_of_B);
                double value_of_retmat = gv_tuples(retmat, x_of_A, y_of_B);

                //create a new variable which is the value of retmat from gv_tuples + (value of A * value of B)
                double new_var = value_of_retmat + (value_at_A * value_at_B);

                set_tuples(retmat, x_of_A, y_of_B, new_var);
            }

            //if row b > col A, stop traversing B
            else if (x_of_B > y_of_A)
            {
                break;
            }

            locusB = locusB->next;  //otherwise set locusB = locusB elements in the next node
            
        }

        locusA = locusA->next;  //otherwise set locusB = locusB elements in the next node
    }
    

    return retmat;

}


	
void destroy_tuples(sp_tuples * mat_t){
    //create node locus and set it to point to the head of mat_t
	sp_tuples_node *locus = mat_t->tuples_head;  
	
	//set new node next to null, will point to next element in node to be looked at
	sp_tuples_node *next = NULL; 
	
	//here we go through the entirety of the locus nodes and its values, saving each new upcoming 
	//ones
	while(locus != NULL){ //while locus is not equal to null
	
	next = locus->next; //set next equal to the element next in locus
	
	free(locus); //free the variable
	
	locus = next; //locus is equal to next
	}
	
	free(mat_t); //free the matrix mat_t
	
    return;
}  






