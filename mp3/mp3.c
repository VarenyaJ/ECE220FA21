// Print a Row from Pascal's Triangle

#include <stdio.h>

int main()
{

  int row;

  printf("Enter a row index: ");
  scanf("%d", &row);

  unsigned long x, i, value; 

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
