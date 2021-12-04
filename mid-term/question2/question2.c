
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this function is a helper function used to check if the data entered by the user is a number
int is_number(char *str)
{
     int i = 0;
     while (str[i] != '\0')
     {
          if (str[i] < '0' || str[i] > '9')
               return 0;
          i++;
     }
     return 1;
}

// this is where the magic happens :) the name says it all :)
int operations(char sheet[6][6][40])
{
     int i, j;
     char cell[4];  // cell name
     int col, row;  // cell coordinates
     char data[20]; // data to be entered
     while (1)
     {
          printf("\nType 'quit' to exit the program\n");
          printf("\nEnter the cell you want to enter data into: ");
          scanf("%s", cell);

          if (strcmp(cell, "quit") == 0)
               return 0; // exit the program if the user types quit

          // lowercase or uppercase letters to reference cells are allowed and must be recognized.
          if (cell[0] >= 'A' && cell[0] <= 'E')
          {
               col = cell[0] - 'A' + 1; // Extracting the column number from the cell number (for upper case letters)
          }
          else if (cell[0] >= 'a' && cell[0] <= 'e')
          {
               col = cell[0] - 'a' + 1; // Extracting the column number from the cell number (for lower case letters)
          }
          else
          {
               printf("\nInvalid cell. Please enter a valid cell.\n");
               continue;
          }

          // the row must be a number between 1 and 5 and must be a number as well to be recognized.
          if (cell[1] >= '1' && cell[1] <= '5')
          {
               row = cell[1] - '0';
          }
          else
          {
               printf("\nInvalid cell. Please enter a valid cell.\n");
               continue;
          }
          
          // if the input exceeds two characters, it is invalid.
          if (strlen(cell) > 2)
          {
               printf("\nInvalid cell. Please enter a valid cell.\n");
               continue;
          }

          printf("\nEnter the data you want to insert: ");
          scanf("%s", data);
          if (strcmp(data, "quit") == 0)
               return 0;
          // if the data is a number, it should be stored as a number.
          if (is_number(data))
          {
               strcpy(sheet[row][col], data);
               // If text entries or other displayed content go beyond the given display size, the display should be truncated
               if (strlen(sheet[row][col]) > 6)
                    sheet[row][col][6] = '\0';
          }
          else
          {
               strcpy(sheet[row][col], data);
               // If text entries or other displayed content go beyond the given display size, the display should be truncated
               if (strlen(sheet[row][col]) > 6)
                    sheet[row][col][6] = '\0';
          }
          // print the updated sheet after entering data into the cell specified by the user input
          for (i = 0; i <= 5; i++)
          {
               for (j = 0; j <= 5; j++)
               {
                    printf("%11s", sheet[i][j]);
               }
               printf("\n");
          }
          // we print what the user inputted so far
          printf("\n\n cell: %s , data: %s \n\n", cell, data);
     }
}

// main function
int main()
{
     int i, j;
     char sheet[6][6][40] = {0}; // the sheet is a 6x6 matrix of strings of size 40
     for (i = 0; i <= 5; i++)
          for (j = 0; j <= 5; j++)
          {
               if (i == 0 && j != 0)
                    sheet[i][j][0] = 'A' + j - 1; // initialize the column labels (A-E)
               else if (j == 0 && i != 0)
                    sheet[i][j][0] = '0' + i; // initialize the row labels (1-5)
               else if (i == 0 && j == 0)
                    sheet[i][j][0] = ' '; // initialize the corner cell with a space
               else
                    sheet[i][j][0] = '_'; // initialize the rest of the cells with an underscore
          }
     // print the initialized sheet
     for (i = 0; i <= 5; i++)
     {
          for (j = 0; j <= 5; j++)
          {
               printf("%11s", sheet[i][j]);
          }
          printf("\n");
     }
     // call the operations function to enter data into the spreadsheet and print the updated sheet after each entry by the user
     operations(sheet);
     return 0;
}
