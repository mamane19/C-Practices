// Write a program that prompts the user for a positive integer and then reports the closest integer having a whole number square root. 
// For example, if the user enters 8, then the program reports 9. If the user enters 18, then the program reports 16. 
// The program should work for any number having one to seven digits. [3 pts]

// For this exercise, I want you to write a C function that takes an integer as input and checks to see if the given integer is a perfect square. 
// Use that function in your program for the above problem

/* 
Author: Bello Moussa Amadou
Date:   04/10/2021
email: b.moussaama@alustudent.com
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void isPerfectSquare(int num)
{
     double sqrtNum = sqrt(num);
     // we want to check if the num is perfect square root.
     if (ceil(sqrtNum) == floor(sqrtNum))
     {
          return;
     }
     else
     {
          return;
     }
}

// a helper function to find the closest number to the given number.
void findClosestSquare(int num)
{
     int i = 1;
     int closestSquare = 0;
     int closestDiff = 0;
     int currentDiff = 0;
     int currentSquare = 0;

     while (currentSquare < num)
     {
          currentSquare = i * i;
          currentDiff = abs(currentSquare - num);
          if (closestDiff == 0 || currentDiff < closestDiff)
          {
               closestDiff = currentDiff;
               closestSquare = currentSquare;
          }
          i++;
     }

     // if the number is a perfect square, then we don't need to find the closest number.
     if (closestDiff == 0)
     {
          printf("%d is a perfect square\n", num);
     }
     else
     {
          printf("%d is the closest square to %d\n", closestSquare, num);
     }
}

// our main function where we will call our helper functions.
int main(void)
{
     int num;
     printf("Enter a number: ");
     scanf("%d", &num);
     if (num < 0)
     {
          printf("%d is not a positive number\n", num);
     }

     else
     {
          isPerfectSquare(num);
          findClosestSquare(num);
     }
     return 0;
}
