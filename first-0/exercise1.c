// Write a C program that sums up the odd and even numbers, respectively,
// from 1 to a given upper bound inclusive (taken as user input).
// The program should then print out the sum of the odd numbers, the sum of the even numbers,
// the absolute difference between the sums, a third of the sum of the even numbers,
// and a 5th of the sum of the odd numbers. Additionally, if the input upper bound is 0 (zero),
// you can give the user additional chances to correct the upper bound to be greater than or equal to 1, without exiting the program.[5 pts]

/* 
Author: Bello Moussa Amadou
Date:   04/10/2021
email: b.moussaama@alustudent.com
*/

#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

int main()
{
     int upper_bound;
     int even_sum = 0;
     int odd_sum = 0;
     int abs_diff = 0;
     double third_even_sum;
     double fifth_odd_sum;
     int i;
     int user_input;

     printf("Enter upper bound: ");
     scanf("%d", &user_input);

     // If the input upper bound is 0 (zero).
     while (user_input == 0 || user_input < 0)
     {
          printf("So you actually believe I can't do that? haha try me harder!!!\n");
          printf("Enter upper bound: ");
          scanf("%d", &user_input);
     }

     // we print the demanded calculations.
     for (i = 1; i <= user_input; i++)
     {
          if (i % 2 == 0)
          {
               even_sum = even_sum + i;
          }
          else
          {
               odd_sum = odd_sum + i;
          }
     }

     abs_diff = abs(even_sum - odd_sum);
     third_even_sum = (even_sum * 0.3333);
     fifth_odd_sum = (odd_sum * 0.2);

     printf("\nThe sum of the odd numbers is %d\n", odd_sum);
     printf("The sum of the even numbers is %d\n", even_sum);
     printf("The absolute difference between the sums is %d\n", abs_diff);
     printf("The third of the sum of the even numbers is %f\n", third_even_sum);
     printf("The fifth of the sum of the odd numbers is %f\n", fifth_odd_sum);

     return 0;
}