#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
     FILE *f;
     char c;
     int nb_words = 0;
     int nb_char = 0;
     int flag = 0;
     int i = 0;

     if (argc != 2)
     {
          printf("Usage: %s <file>\n", argv[0]);
          exit(1);
     }

     f = fopen(argv[1], "r");
     if (f == NULL)
     {
          printf("Error: can't open file %s\n", argv[1]);
          exit(1);
     }

     while ((c = fgetc(f)) != EOF)
     {
          if (c == ' ' || c == '\n' || c == '\t')
          {
               if (flag == 1)
                    nb_words++;
               flag = 0;
          }
          else
          {
               flag = 1;
               nb_char++;
          }
     }
     fclose(f);

     printf("%d words\n", nb_words);
     printf("%d characters\n", nb_char);

     return 0;
}
