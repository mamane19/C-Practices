// Write a C program to print the following pyramid [5pts]

//                *
//               * *
//              * * *
//             * * * *
//            * * * * *
//            * * * * *
//             * * * *
//              * * *
//               * *
//                *

/* 
Author: Bello Moussa Amadou
Date:   04/10/2021
email: b.moussaama@alustudent.com
*/
#include <stdio.h>

int main()
{
     int col, row;
     int space = 4;

     for (col = 1; col <= 5; col++)
     {
          for (row = 1; row <= space; row++)
          {
               printf(" ");
          }
          for (row = 1; row <= col; row++)
          {
               printf("* ");
          }
          printf("\n");
          space--;
     }

     space = 0;
     for (col = 5; col >= 1; col--)
     {
          for (row = 1; row <= space; row++)
          {
               printf(" ");
          }
          for (row = 1; row <= col; row++)
          {
               printf("* ");
          }
          printf("\n");
          space++;
     }

     return 0;
}