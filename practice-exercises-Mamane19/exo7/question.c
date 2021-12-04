#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer
{
     char name[20];
     int account_number;
     float balance;
};

void print_names(struct customer *customer_list, int n)
{
     int i;
     for (i = 0; i < n; i++)
     {
          if (customer_list[i].balance < 200)
          {
               printf("%s \n", customer_list[i].name);
          }
     }
}

void add_100(struct customer *customer_list, int n)
{
     int i;
     for (i = 0; i < n; i++)
     {
          if (customer_list[i].balance > 1000)
          {
               customer_list[i].balance += 100;
          }
     }
}

int main()
{
     int n;
     printf("Enter the number of customers: ");
     scanf("%d", &n);
     struct customer *customer_list = (struct customer *)malloc(n * sizeof(struct customer));
     int i;
     for (i = 0; i < n; i++)
     {
          printf("Enter the name of customer %d: ", i + 1);
          scanf("%s", customer_list[i].name);
          printf("Enter the account number of customer %d: ", i + 1);
          scanf("%d", &customer_list[i].account_number);
          printf("Enter the balance of customer %d: ", i + 1);
          scanf("%f", &customer_list[i].balance);
     }
     printf("\nThe names of customers having a balance of less than $200 are: \n");
     print_names(customer_list, n);
     add_100(customer_list, n);
     printf("\n");
     printf("These are the customers having more than 1000$ and the added 100$ for each: \n");
     if (n > 0)
     {
          for (i = 0; i < n; i++)
          {
               if (customer_list[i].balance > 1000)
               {
                    printf("%s\t%d\t%.2f\n", customer_list[i].name, customer_list[i].account_number, customer_list[i].balance);
               }
          }
     }
     else
     {
          printf("No customers found.\n");
     }
     // for (i = 0; i < n; i++)
     // {
     //      printf("%s\t%d\t%.2f\n", customer_list[i].name, customer_list[i].account_number, customer_list[i].balance);
     // }
     return 0;
}