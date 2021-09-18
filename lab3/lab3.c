#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846


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

    printf("Please enter the desired values of n, ω1, and ω2 in that order: \n");
    scanf("%d %f %f", &n, &omega1, &omega2);

//negativ line inputs
//check for proper inputs
//uneven parens with negative results

//loop from 0 to 1
//caclutate both results

    for(int i=0; i<n; i++)
    {
        float res1 = (M_PI*i) / n;
        float res2 = sin(res1*omega1) + (sin(res1*omega2)) /2;
    
        printf("%f, %f\n", res1, res2);
    }
    


    return 0;
}
