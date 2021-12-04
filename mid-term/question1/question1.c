
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>



void count_unique_words(char *filename)
{
     int fd = open(filename, O_RDONLY);
     if (fd == -1)
     {
          printf("Error opening file\n");
          exit(1);
     }

     // Count the number of words in the file
     int num_words = 0;
     char c;
     while (read(fd, &c, 1) != 0)
     {
          if (c == ' ' || c == '\n')
          {
               num_words++;
          }
     }
     close(fd);

     // Create an array to store the words
     char *words[num_words];

     // Fork the process
     pid_t pid = fork();
     if (pid == -1)
     {
          printf("Error creating child process\n");
          exit(1);
     }

     // Child process
     if (pid == 0)
     {
          // Read the file
          fd = open(filename, O_RDONLY);
          if (fd == -1)
          {
               printf("Error opening file\n");
               exit(1);
          }

          // Read the words in the file
          int i = 0;
          char word[200];
          while (read(fd, &c, 1) != 0)
          {
               if (c == ' ' || c == '\n')
               {
                    words[i] = strdup(word);
                    i++;
                    memset(word, 0, sizeof(word));
               }
               else
               {
                    strncat(word, &c, 1);
               }
          }
          close(fd);

          // Create a hashmap to store the words and their count without duplicates. We only need to  increment the count
          // if the word is already present in the hashmap
          int hashmap[256];
          for (int i = 0; i < 256; i++)
          {
               hashmap[i] = 0;
          }

          // Count the number of unique words in the file
          int num_unique_words = 0;
          for (int i = 0; i < num_words; i++)
          {
               for (int j = 0; j < num_words; j++)
               {
                    if (strcmp(words[i], words[j]) == 0)
                    {
                         hashmap[i]++;
                    }
               }
          }

          // Print the unique words and their count in a gian hashmap
          printf("{");
          for (int i = 0; i < num_words ; i++)
          {
               if (hashmap[i] == 1)
               {
                    printf("'%s': %d, ", words[i], hashmap[i]);
                    num_unique_words++;
               }
               
          }
          printf("}\n");
          // Exit the child process
          exit(0);
     }

     // Parent process
     else
     {
          // Wait for the child process to finish
          int status;
          wait(&status);
     }
}


int main(int argc, char *argv[])
{
     if (argc != 2)
     {
          printf("Usage: ./a.out <filename>\n");
          exit(1);
     }

     count_unique_words(argv[1]);
     return 0;
}
