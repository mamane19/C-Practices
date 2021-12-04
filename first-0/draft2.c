int enter_data(char sheet[6][6][11])
{
     char cell[4];
     int i, j,col,row;
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
               col = cell[0] - 'A' +1;
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
          
          printf("\nEnter the data you want to enter: ");
          scanf("%s", data);
          if (strcmp(data, "quit") == 0)
               return 0;
          if (is_number(data))
          {
               strcpy(sheet[row][col], data);

               if (strlen(sheet[row][col]) > 10)
                    sheet[row][col][10] = '\0';
          }
          else
          {
               strcpy(sheet[row][col], data);
               if (strlen(sheet[row][col]) > 10)
                    sheet[row][col][10] = '\0';
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
          printf("\n\n Cell Number: %s , data: %s \n\n", cell, data);
     }
}

