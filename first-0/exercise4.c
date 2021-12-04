// Let's code a game

// This program will read a random number (like the program generates a random number)
// and ask the user to guess it. The user has to guess the number that the program generated.
// The program will give 10 attempts to guess the number, on each attempt, the program will inform
// that the entered number is less than or greater than the randomly generated number so that the user can easily guess that particular number. [2 pts]

// If the user guesses the number, you congratulate them and you tell them the number of guesses they made.

// Eg: congratulations, you made 5 guesses.
/* 
Author: Bello Moussa Amadou
Date:   04/10/2021
email: b.moussaama@alustudent.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
     int number, guess, guess_count = 0;
     srand(time(NULL));
     number = rand() % 100 + 1;
     printf("Guess the number: ");
     scanf("%d", &guess);
     while (guess != number)
     {
          guess_count++;
          if (guess < number)
          {
               printf("Your guess is less than the number.\n");
          }
          else
          {
               printf("Your guess is greater than the number.\n");
          }
          printf("Guess the number: ");
          scanf("%d", &guess);
          if (guess_count == 10)
          {
               printf("You took 10 guesses without guessing it, Sorry but you are a loser hahaha.\n");
               break;
          }
          else if (guess == number)
          {
               printf("Congratulations, you made %d guesses.\n", guess_count);
          }
     }
     return 0;
}
