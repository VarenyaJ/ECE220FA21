/* Function matrix_multiply
 * matrixA, matrixB, and matrix C are matrices represented as
 * one-dimensional arrays in row-major order. This function must
 * preform matrix multiplication so that C=A*B.
 * INPUT: matrixA, a one dimensional array of size m*k
 *        matrixB, a one dimensional double array of size k*n
 * OUTPUT: matrixC, a one dimensional double array of size m*n
 */
void matrix_multiply(double *matrixA,double *matrixB,double *matrixC,int m,int k,int n)
{
//YOUR CODE HERE
    int i, j, l;
    //for all m rows of matrix A
    for(i=0; i<m; i++)
    {
        //for all n columns of matrix B
        for(j=0; j<n; j++)
        {
            matrixC[i*n+j]=0;   //clear C_ij

            //for all elements in the k-length dot product
            for(l=0; l<k; l++)
            {
                matrixC[i*n+j] += matrixA[i*k+l] * matrixB[l*n+j];  //add A_il * B_lj
            }
        }
    }
}
