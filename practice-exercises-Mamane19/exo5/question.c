#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, i;
     int *p;
     printf("Enter the number of elements: ");
     scanf("%d", &n);
     p = (int *)malloc(n * sizeof(int));
     for (i = 0; i < n; i++)
     {
          printf("Enter the element %d: ", i + 1);
          scanf("%d", &p[i]);
     }
     printf("The elements are: ");
     for (i = 0; i < n; i++)
     {
          printf("%d ", p[i]);
     }
     printf("\n");
     free(p);
     return 0;
}