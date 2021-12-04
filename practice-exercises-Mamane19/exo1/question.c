#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
     int i, j, nb, min, max, max_occurence, occurence, nb_occurence, nb_value;
     int tab[10];

     printf("Entrez 10 numbers :\n");

     for (i = 0; i < 10; i++)
     {
          printf("Number %d : ", i + 1);
          scanf("%d", &nb);
          tab[i] = nb;
     }

     min = tab[0];
     max = tab[0];

     for (i = 0; i < 10; i++)
     {
          if (tab[i] < min)
          {
               min = tab[i];
          }
          if (tab[i] > max)
          {
               max = tab[i];
          }
     }

     printf("\nThe smallest number is : %d\n", min);
     printf("The biggest number is : %d\n", max);

     max_occurence = 0;
     occurence = 0;
     nb_occurence = 0;
     nb_value = 0;

     for (i = 0; i < 10; i++)
     {
          for (j = 0; j < 10; j++)
          {
               if (tab[i] == tab[j])
               {
                    occurence++;
               }
          }
          if (occurence > max_occurence)
          {
               max_occurence = occurence;
               nb_value = tab[i];
          }
          occurence = 0;
     }

     printf("The number that occurs the most is : %d\n", nb_value);

     return 0;
}