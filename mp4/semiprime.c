#include <stdlib.h>
#include <stdio.h>

/*
Errors:
1) <is_prime>: for cases where numbers were prime or composite, the return values were switched. The composite case should return 0 and the prime case should return 1, but this error would result in the semiprime function checking numbers for composite factors instead prime factors

2) <print_semiprimes> : the value of k should be "k=i/j", not "k=j/i". When checking whether or not to print a number, we need to make sure that the facors of i, j, and k are primes. leaving this error alone would mean that for all semiprimes, k evaluate to 0 since j is a factor of i. Since 0 is not a prime number, the semiprime bumbers would not print, as they are only printed when k is prime.

3 <print_semiprimes>: the program does not exit the "for loop" with "j". To counter this, we need a bread statement after the printf statement. Without this, we will print semiprimes including and above 6 more than once. 

*/


/*
 * is_prime: determines whether the provided number is prime or not
 * Input    : a number
 * Return   : 0 if the number is not prime, else 1
 */
int is_prime(int number)
{
    int i;
    if (number == 1) {return 0;}
    for (i = 2; i < number; i++) { //for each number smaller than it
        if (number % i == 0) { //check if the remainder is 0
            return 0;	//changed "return 1" to "return 0"
        }
    }
    return 1;	//changed "return 0" to "return 1"
}


/*
 * print_semiprimes: prints all semiprimes in [a,b] (including a, b).
 * Input   : a, b (a should be smaller than or equal to b)
 * Return  : 0 if there is no semiprime in [a,b], else 1
 */
int print_semiprimes(int a, int b)
{
    int i, j, k;
    int ret = 1;	//changed "ret 0" to "ret 1"
    for (i = a; i <=b; i++) { //for each item in interval
        //check if semiprime
        for (j = 2; j <= i; j++) {
            if (i%j == 0) {
                if (is_prime(j)) {
                    k = i/j;	//change " % " to " / "
                    if (is_prime(k)) {
                        printf("%d ", i);
			break;	//add this line to allow for exiting the inner-most loop and further increment i
                    }
                }
            }
        }

    }
    printf("\n");
    return ret;

}
