// Write a C program that will count uppercase, lowercase and special characters in a sentence.
// Use a sub-function to count the uppercase, lowercase, special characters for each word in the
// sentence and call this sub-function in the main() where you will display the total counts for the 3 categories.  [3 pts]

// Goals: loops and conditions, strings & functions

// The logic behind implementing this program is too easy, just check if characters are alphabet or not,
// if it is alphabet check for lower and upper case characters, if characters are not alphabets count them as special characters.

/* 
Author: Bello Moussa Amadou
Date:   04/10/2021
email: b.moussaama@alustudent.com
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of uppercase, lowercase and special characters in a string
void count_characters(char *str)
{
     int i, uppercase = 0, lowercase = 0, special_characters = 0;

     for (i = 0; i < strlen(str); i++)
     {
          if (isalpha(str[i]))
          {
               if (isupper(str[i]))
               {
                    uppercase++;
               }
               else
               {
                    lowercase++;
               }
          }
          else
          {
               special_characters++;
          }
     }

     printf("Uppercase characters: %d\n", uppercase);
     printf("Lowercase characters: %d\n", lowercase);
     printf("Special characters: %d\n", special_characters);
}

int main()
{
     char str[100];

     printf("Enter a string: ");
     scanf("%s", str);

     if (strlen(str) == 0)
     {
          printf("The string is empty.\n");
     }
     else if (strlen(str) > 0)
     {
          if (strlen(str) > 100)
          {
               printf("The string is too long.\n");
          }
          else
          {
               if (strlen(str) == 1)
               {
                    if (isalpha(str[0]))
                    {
                         if (isupper(str[0]))
                         {
                              printf("The string contains only one uppercase characters.\n");
                         }
                         else
                         {
                              printf("The string contains only one lowercase characters.\n");
                         }
                    }
                    else
                    {
                         printf("The string contains only one special characters.\n");
                    }
               }
               else
               {

                    count_characters(str);
               }
          }
     }

     return 0;
}