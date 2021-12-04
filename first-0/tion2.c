// Write a program that mimics a simple spreadsheet. The program should allow the user to enter numeric values, text into any cell.
// As new data is entered, the spreadsheet should be updated and redisplayed. The program should run until the user quits.

// The maximum size of the spreadsheet should be 5 x 5 cells. Rows should be labeled with numbers, starting from 1, and columns should
// be labeled with letters, starting from A. Cells should be referenced by a letter number pair, with no space or symbol between;
// for example, E4. Lowercase and uppercase letters to reference cells are allowed and must be recognized.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

// a function to initialize the spreadsheet with default values. Columns are labeled with letters, starting from A.
// Rows are labeled with numbers, starting from 1.
int initialize_sheet()
{
     int i, j;
     char sheet[6][6][11] = {0};
     for (i = 0; i <= 5; i++)
          for (j = 0; j <= 5; j++)
          {
               if (i == 0 && j != 0)
                    sheet[i][j][0] = 'A' + j - 1;
               else if (j == 0 && i != 0)
                    sheet[i][j][0] = '0' + i;
               else if (i == 0 && j == 0)
                    sheet[i][j][0] = ' ';
               else
                    sheet[i][j][0] = '_';
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
     // return 1;

     char cell[4];
     int col, row;
     char data[20];
     while (1)
     {
          printf("\nType 'quit' to exit the program\n");
          printf("\nEnter the cell you want to enter data into: ");
          scanf("%s", cell);

          if (strcmp(cell, "quit") == 0)
               return 0;

          // lowercase or uppercase letters to reference cells are allowed and must be recognized.
          if (cell[0] >= 'A' && cell[0] <= 'E')
          {
               col = cell[0] - 'A' + 1;
          }
          else if (cell[0] >= 'a' && cell[0] <= 'e')
          {
               col = cell[0] - 'a' + 1;
          }
          else
          {
               printf("\nInvalid cell. Please enter a valid cell.\n");
               continue;
          }

          // the cell should be referenced by a letter number pair, with no space or symbol between;
          // for example, E4.
          // if (cell[0] >= 'A' && cell[0] <= 'E')
          // {
          //      col = cell[0] - 'A' + 1;
          //      row = cell[1] - '0';
          // } else {
          //      col = cell[0] - 'a' + 1;
          //      row = cell[0] - '0';
          // }
          row = cell[1] - '1' + 1;
          if (row > 5 || row < 0 || col > 5 || col < 0)
          {
               printf("\nInvalid cell. Please enter a valid cell.\n");
               continue;
          }

          printf("\nEnter the data you want to insert: ");
          scanf("%s", data);
          if (strcmp(data, "quit") == 0)
               return 0;
          if (is_number(data))
          {
               strcpy(sheet[row][col], data);

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


int main()
{
     // char sheet[6][6][11] = {0};
     initialize_sheet();
     // operations();
     return 0;
}
