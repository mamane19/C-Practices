#include <stdio.h>

int main(void)
{
     int tab[2];
     int *p, nb, i;
     printf("Entez two numbers : \n");
     for (i = 0; i < 2; i++)
     {
          printf("number %d : " , i + 1);
          scanf("%d", &nb);
          tab[i] = nb;
     }
     p = &tab[0];
     if (*p > *(p + 1))
     {
          printf("The maximum number between %d and %d is: %d\n", tab[0], tab[1], *p);
     }
     else
     {
          printf("The maximum number between %d and %d is %d\n", tab[0], tab[1], *(p + 1));
     }
}