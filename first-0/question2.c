// Write a program that mimics a simple spreadsheet. The program should allow the user to enter numeric values, text into any cell.
// As new data is entered, the spreadsheet should be updated and redisplayed. The program should run until the user quits.

// The maximum size of the spreadsheet should be 5 x 5 cells. Rows should be labeled with numbers, starting from 1, and columns should
// be labeled with letters, starting from A. Cells should be referenced by a letter number pair, with no space or symbol between;
// for example, E4. Lowercase and uppercase letters to reference cells are allowed and must be recognized.

// The program cannot prompt what type of entry is being made into a cell. It should prompt only for an input. If the user types data
// consisting only of numeric values, for example 4.53, then the program must recognize that input as a number. All numbers should be
// considered real numbers. Everything else defaults to text. The display of the spreadsheet should be aligned in an easy-to-read
// 5 x 5 grid. If text entries or other displayed content go beyond the given display size, the display should be truncated.
// When entering a new input for a cell, the program must display the old (previous) input.

// HINT : Use multi-Dimensional Arrays [Matrix form], you can use Standard C library functions wherever required. [CS50 - Not permitted]

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int isNumber(char str[20])
{
     int i, j, k, flag = 1;
     for (i = 0; str[i] != '\0'; i++)
     {
          if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'))
          {
          }
          else
          {
               flag = 0;
               break;
          }
     }
     return flag;
}
int main()
{
     int row, col, i, j;
     // double spreadsheet[10][10] = {0}; // matrix to store the Integer values entered by the user and the values computed as result of formula
     char sheet[6][6][11] = {0};     // The actual spreadsheet which stores the content to be displayed
     // int flag[10][10] = {0};           // Flag matrix to check whether cell contains value entered by the user or the one computed by the formula
     char input[20]; // Input value received from user

     char cellnum[4]; // Cell number received from the user
     // char *sub;
     for (i = 0; i <= 5; i++) // Initialization of the sheet matrix to contain default values
          for (j = 0; j <= 5; j++)
          {
               if (i == 0 && j != 0)
                    sheet[i][j][0] = 'A' + j - 1;
               else if (i != 0 && j == 0)
                    sheet[i][j][0] = '0' + i;
               else if (i == 0 && j == 0)
                    sheet[i][j][0] = '\0';
               else
                    sheet[i][j][0] = '_';
          }
     while (1) // Infinite loop to take input till user quits
     {
          printf("\ntype 'quit' to quit\n");
          printf("\nEnter the cell number in this format (eg: A1, E5):  ");
          scanf("%s", cellnum);

          if (strcmp(cellnum, "quit") == 0)
               break;

          if (cellnum[0] >= 'A' && cellnum[0] <= 'E')
               col = cellnum[0] - 'A' + 1; // Extracting the column number from the cell number (for upper case letters)
          else
               col = cellnum[0] - 'a' + 1; // Extracting the row and column number from cell number (for lowercase letters)
          row = cellnum[1] - '1' + 1;
          if (row > 5 || row < 0 || col > 5 || col < 0)
          {
               printf("\n Invalid cell number \n");
               continue;
          }
          printf("\nEnter the value to be inserted  :  ");
          scanf("%s", input);

          if (isNumber(input)) // Checking if the value entered by the user is a number
          {
               // spreadsheet[row][col] = atoi(input);
               // flag[row][col] = 1;
               strcpy(sheet[row][col], input);
               // If the text entered is more than 5 characters, truncate it
               if (strlen(sheet[row][col]) > 5)
               {
                    sheet[row][col][6] = '.';
                    sheet[row][col][7] = '.';
                    sheet[row][col][8] = '\0';
               }
          }
          else
          {
               // If value entered is text ,  simply insert the text into the cell
               strcpy(sheet[row][col], input);
               // If the text entered is more than 5 characters, truncate it
               if (strlen(sheet[row][col]) > 5)
               {
                    sheet[row][col][6] = '.';
                    sheet[row][col][7] = '.';
                    sheet[row][col][8] = '\0';
               }
          }

          // Printing the updated spreadsheet
          for (i = 0; i <= 5; i++)
          {
               for (j = 0; j <= 5; j++)
                    printf("%8s   ", sheet[i][j]);
               printf("\n");
          }

          printf("\n\n Pervious input  :  Cell Number : %s , Value : %s\n\n", cellnum, input);
     }
     return 0;
}
