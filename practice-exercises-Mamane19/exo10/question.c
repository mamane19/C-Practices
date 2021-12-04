#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
     int fd[2];
     pipe(fd);

     if (fork() == 0)
     {
          close(fd[0]);
          write(fd[1], "Hey Mamane", 13);
          close(fd[1]);
     }
     else
     {
          close(fd[1]);
          char buf[20];
          read(fd[0], buf, sizeof(buf));
          printf("%s\n", buf);
          close(fd[0]);
     }
     return 0;
}

/// Second temptation below

// int main(int argc, char *argv[])

// {
//      int pid;
//      int fd[2];
//      char buffer[256];
//      char *str = "Hello from child";
//      char *str1 = "Hello from parent";

//      pipe(fd);
//      pid = fork();

//      if (pid == -1)
//      {
//           perror("fork");
//           exit(1);
//      }

//      if (pid == 0)
//      {
//           close(fd[0]);
//           write(fd[1], str, strlen(str));
//           close(fd[1]);
//           exit(0);
//      }
//      else
//      {
//           close(fd[1]);
//           read(fd[0], buffer, 256);
//           printf("%s\n", buffer);
//           close(fd[0]);
//           printf("%s\n", str1);
//      }
//      return 0;
// }