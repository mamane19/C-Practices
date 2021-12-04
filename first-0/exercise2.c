// Write a program that prompts the user for a positive integer and then computes the sum of all the digits of the number.
// For example, if the user enters 2784, then the program reports 21. If the user enters 59, then the program reports 14.
// The program should work for any number having one to ten digits.   [2 pts]

/* 
Author: Bello Moussa Amadou
Date:   04/10/2021
email: b.moussaama@alustudent.com
*/

#include <stdio.h>

int main(void)
{
     int number;
     int sum = 0;
     printf("Enter a positive integer: ");
     scanf("%d", &number);
     while (number > 0)
     {

          sum += number % 10;
          number /= 10;
     }
     printf("The sum of the digits is: %d.\n", sum);
     return 0;
}