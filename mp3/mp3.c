// Print a Row from Pascal's Triangle

#include <stdio.h>

int main()
{

  //declare row counter
  int row;

  printf("Enter a row index: ");
  scanf("%d", &row);

  //use unsigned long for these values since the math is wrong with integers
  //e.g. (10 * 3) / 3 ≠ (10 / 3) * 3 --> 10 ≠ 9
  
  
  unsigned long x, i, value; 

  // in each loop, the declared variable should be less than the one declared before/outside of the respective loop
  for (x = 0; x <= row; x++){

        value = 1; 

        for (i = 1; i <= x; i++){ 
            
            value = (value * (row +1 -i))/i;
        }
    
        printf ("%lu ", value);
  }
  
  printf("\n");
  return 0;
}
