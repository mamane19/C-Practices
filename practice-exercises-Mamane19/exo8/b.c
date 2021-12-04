#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1000

int main()
{
     /* File pointer to hold reference of input file */
     FILE *fPtr;
     FILE *fTemp;
     char path[100];

     char buffer[MAX_LINE];
     char newline[MAX_LINE];
     int line, count;

     printf("Enter path of source file: ");
     scanf("%s", path);
     if ((fPtr = fopen(path, "r")) == NULL)
     {
          printf("Error opening file\nPlease check the file path\n");
          exit(1);
     }

     printf("Enter line number to replace: ");
     scanf("%d", &line);

     /* Remove extra new line character from stdin */
     fflush(stdin);
     printf("Replace '%d' line with: ", line);

     fgets(newline, MAX_LINE, stdin);
     scanf("%[^\n]", newline);

     /*  Open all required files */
     fPtr = fopen(path, "r");
     fTemp = fopen("replace.tmp", "w");
     if (fPtr == NULL || fTemp == NULL)
     {
          printf("Error opening file\n");
          exit(1);
     }

     count = 1;
     while ((fgets(buffer, MAX_LINE, fPtr)) != NULL)
     {

          if (count == line)
               fprintf(fTemp, "%s\n", newline);
          else
               fprintf(fTemp, "%s", buffer);

          count++;
     }

     fclose(fPtr);
     fclose(fTemp);

     remove(path);

     rename("replace.tmp", path);

     printf("\nSuccessfully replaced '%d' line with '%s'.\n", line, newline);

     return 0;
}