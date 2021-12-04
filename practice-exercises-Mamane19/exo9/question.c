#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
     int pid, pid1, pid2;

     pid = fork();
     if (pid == 0)
     {
          sleep(3);
          printf("Child 1: PID = %d\n", getpid());
     }
     else
     {
          pid1 = fork();
          if (pid1 == 0)
          {
               sleep(2);
               printf("Child 2: PID = %d\n", getpid());
          }
          else
          {
               pid2 = fork();
               if (pid2 == 0)
               {
                    printf("Child 3: PID = %d\n", getpid());
                    sleep(1);
               }
               else
               {
                    sleep(3);
                    printf("Parent: PID = %d\n", getpid());
               }
          }
     }

     return 0;
}
