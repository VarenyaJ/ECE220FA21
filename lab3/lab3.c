//this program implements code that computes function:

//f(x)=sin(ω1x)+12sin(ω2x)
//on the interval x∈[0,π]. You program must ask user to enter all relevant values (n, ω1, ω2) and must print a table of n pairs (xi,f(xi)) where i=0,1,…,(n−1) and 

//xi=iπn. Implementation must use a loop construct a



#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
//define pi early on

int main()
{

/*
gcc -g -Wall -std=c99 -lm lab3.c -o lab3
<-std=c99> = standard 99 for C. Wihtout it, certain things don't work, such as declaring a variable inside of a loop
<-g> = lets you debug
<-Wall> = sets all warning to on
<-lm> = links math library
<./lab3> = runs the output file //
use <scanf> to read in n and both omegas
*/




//need to pass <scanf> the address of these variables (passing in a variable stores
//a copy of the variable in an address)

//Get the input

    int n;
    float omega1, omega2;

    //use floating point numbers for scanning in
    
    printf("Please enter the desired values of n, ω1, and ω2 in that order: \n");
    scanf("%d %f %f", &n, &omega1, &omega2);

//negative line inputs?
//check for proper inputs?
//uneven parens with negative results?

//loop from 0 to 1
//caclutate both results

    //loop for the actual function
    for(int i=0; i<n; i++)
    {
        float res1 = (M_PI*i) / n;
        float res2 = sin(res1*omega1) + (sin(res1*omega2)) /2;
    
        printf("%f, %f\n", res1, res2);
    }
    


    return 0;
}
