// void count_words(char *filename) 
// { 
//      // Open file 
//      FILE *fp = fopen(filename, "r"); 
//      if (fp == NULL) 
//      { 
//           printf("Could not open file %s", filename); 
//           return; 
//      } 

//      // Initialize hash table 
//      int i; 
//      int hash_table[26] = {0}; 

//      // Read file contents 
//      char c; 
//      while ((c = fgetc(fp)) != EOF) 
//      { 
//           // If the character is a letter, increment the count of the letter 
//           if (c >= 'a' && c <= 'z') 
//                hash_table[c - 'a']++; 
//      } 

//      // Print the contents of the hash table 
//      for (i = 0; i < 26; i++) 
//           if (hash_table[i] != 0) 
//                printf("%c: %d\n", i + 'a', hash_table[i]); 

//      // Close file 
//      fclose(fp); 
// }


// // Function to count the number of unique words in a file
// void count_words_fork(char *filename) 
// { 
//      // Open file 
//      FILE *fp = fopen(filename, "r"); 
//      if (fp == NULL) 
//      { 
//           printf("Could not open file %s", filename); 
//           return; 
//      } 

//      // Initialize hash table 
//      int i; 
//      int hash_table[26] = {0}; 

//      // Read file contents 
//      char c; 
//      while ((c = fgetc(fp)) != EOF) 
//      { 
//           // If the character is a letter, increment the count of the letter 
//           if (c >= 'a' && c <= 'z') 
//                hash_table[c - 'a']++; 
//      } 

//      // Print the contents of the hash table 
//      for (i = 0; i < 26; i++) 
//           if (hash_table[i] != 0) 
//                printf("%c: %d\n", i + 'a', hash_table[i]); 

//      // Close file 
//      fclose(fp); 
// }


// Write a C program that reads the content of a file, and prints out all unique words from the file and their number of occurrences.
// Your program should use fork() , divide relevant tasks between parent and child/children(ren) and combine the contents together
// for processing. You can create as many forks as you want as long as you have more than one process including the parent process.
// In the Readme, write your thought process when solving this problem

// i.e:
// [input]
// file.txt =
// Lorem Ipsum has been the industry's standard dummy text ever since the 1500s when an unknown printer took a galley of type and
// scrambled it to make a type specimen book.

// [output]
// {'Lorem': 1, 'Ipsum': 1, 'has': 1, 'been': 1, 'the': 2, "industry's": 1, 'standard': 1, 'dummy': 1, 'text': 1, 'ever': 1,
// 'since': 1, '1500s,': 1, 'when': 1, 'an': 1, 'unknown': 1, 'printer': 1, 'took': 1, 'a': 2, 'galley': 1, 'of': 1, 'type': 2,
// 'and': 1, 'scrambled': 1, 'it': 1, 'to': 1, 'make': 1, 'specimen': 1, 'book.': 1}

// [input]
// file.txt =
// Lorem Ipsum has been the industry's standard dummy text ever since the 1500s when an unknown printer took a galley of type and
// scrambled it to make a type specimen book.

// [output]
// {'Lorem': 1, 'Ipsum': 1, 'has': 1, 'been': 1, 'the': 2, "industry's": 1, 'standard': 1, 'dummy': 1, 'text': 1, 'ever': 1,
// 'since': 1, '1500s,': 1, 'when': 1, 'an': 1, 'unknown': 1, 'printer': 1, 'took': 1, 'a': 2, 'galley': 1, 'of': 1, 'type': 2,
// 'and': 1, 'scrambled': 1, 'it': 1, 'to': 1, 'make': 1, 'specimen': 1, 'book.': 1}

// C program to count the number of unique words in a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

// Function to count the number of unique words in a file using fork() and creating parent and child processes
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
          char word[100];
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
          int hashmap[26];
          for (int i = 0; i < 26; i++)
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
          for (int i = 0; i < num_words; i++)
          {
               if (hashmap[i] == 1)
               {
                    printf("'%s': %d, ", words[i], hashmap[i]);
                    num_unique_words++;
               }
               
          }
          // Print the number of unique words in the file
          printf("}\n");
          // for (int i = 0; i < num_words; i++)
          // {
          //      if (hashmap[i] == 1)
          //      {
          //           printf("%s: %d\n", words[i], hashmap[i]);
          //           num_unique_words++;
          //      }
          // }
          // printf("Number of unique words: %d\n", num_unique_words);
          // exit(0);

          // Exit the child process
          exit(0);
     }

     // Parent process
     else
     {
          // Wait for the child process to finish
          wait(NULL);
     }
}

//           // Print the unique words and their count
//           printf("{");
//           for (i = 0; i < unique_words; i++)
//           {
//                if (i != 0)
//                {
//                     printf(", ");
//                }
//                printf("'%s': %d", words[hashmap[i]], 1);
//           }
//           printf("}\n");

//           // Exit the child process
//           exit(0);
//      }

//      // Parent process
//      else
//      {
//           // Wait for the child process to finish
//           int status;
//           waitpid(pid, &status, 0);
//      }
// }

// // Count the number of occurrences of each word in the file and remove duplicates
// for (int i = 0; i < num_words; i++)
// {
//      for (int j = 0; j < num_words; j++)
//      {
//           if (strcmp(words[i], words[j]) == 0)
//           {
//                hash_map[i]++;
//           }
//      }
// }

// // Print the words and their count in a one giant hashmap.
// printf("{");
// for (int i = 0; i < num_words; i++)
// {
//      if (words[i] != NULL)
//      {
//           printf("'%s': %d", words[i], hash_map[i]);
//           if (i != num_words - 1)
//           {
//                printf(", ");
//           }
//      }
// }
// printf("}\n");

// // Exit the child process
// exit(0);
// }

// // Parent process
// else
// {
//      // Wait for the child process to finish
//      wait(NULL);
// }
// }

int main(int argc, char *argv[])
{
     // Check if the user has entered the correct number of arguments
     if (argc != 2)
     {
          printf("Usage: ./a.out <filename>\n");
          exit(1);
     }

     // Call the function to count the number of unique words in the file
     count_unique_words(argv[1]);

     return 0;
}





// for (i = 0; i < num_words; i++)
//           {
//                int index = 0;
//                char *word = words[i];
//                for (int j = 0; j < strlen(word); j++)
//                {
//                     index += (int)word[j];
//                }
//                index = index % 52;

//                // If the word is already present in the hash table, increment the count
//                if (hash_table[index] != 0)
//                {
//                     hash_table[index]++;
//                }
//                // Else add the word to the hash table
//                else
//                {
//                     hash_table[index] = 1;
//                }
//           }


void count_unique_words(char *filename)
// {
//      // Open the file
//      int fd = open(filename, O_RDONLY);
//      if (fd == -1)
//      {
//           perror("open");
//           exit(EXIT_FAILURE);
//      }

//      // Read the file
//      char *buffer = (char *)malloc(sizeof(char) * 1024);
//      if (buffer == NULL)
//      {
//           perror("malloc");
//           exit(EXIT_FAILURE);
//      }

//      // Read the file
//      int bytes_read = read(fd, buffer, 1024);
//      if (bytes_read == -1)
//      {
//           perror("read");
//           exit(EXIT_FAILURE);
//      }

//      // Close the file
//      if (close(fd) == -1)
//      {
//           perror("close");
//           exit(EXIT_FAILURE);
//      }

//      // Count the number of unique words in the file
//      int num_unique_words = 0;
//      char *word = (char *)malloc(sizeof(char) * 1024);
//      if (word == NULL)
//      {
//           perror("malloc");
//           exit(EXIT_FAILURE);
//      }

//      // Count the number of unique words in the file
//      int i = 0;
//      while (i < bytes_read)
//      {
//           // Skip all non-alphabetic characters
//           while (i < bytes_read && !isalpha(buffer[i]))
//           {
//                i++;
//           }

//           // Read the word
//           int j = 0;
//           while (i < bytes_read && isalpha(buffer[i]))
//           {
//                word[j] = buffer[i];
//                i++;
//                j++;
//           }
//           word[j] = '\0';

//           // Skip all non-alphabetic characters
//           while (i < bytes_read && !isalpha(buffer[i]))
//           {
//                i++;
//           }

//           // Check if the word is already in the dictionary
//           int found = 0;
//           for (int k = 0; k < num_unique_words; k++)
//           {
//                if (strcmp(word, word[k]) == 0)
//                {
//                     found = 1;
//                     break;
//                }
//           }

//           // Add the word to the dictionary
//           if (!found)
//           {
//                num_unique_words++;
//                word[num_unique_words] = word;
//           }
//      }

//      // Print the dictionary
//      printf("{");
//      for (int i = 0; i < num_unique_words; i++)
//      {
//           if (i < num_unique_words - 1)
//           {
//                printf(", ");
//           }
//           printf("'%s': %d", word[i], 1);
//      }
//      printf("}\n");

//      // Free the memory
//      // free(buffer);
//      // free(word);
// }

// // Main function
// int main(int argc, char *argv[])
// {
//      // Check the number of arguments
//      if (argc != 2)
//      {
//           printf("Usage: %s <filename>\n", argv[0]);
//           exit(EXIT_FAILURE);
//      }

//      // Fork the process
//      pid_t pid = fork();
//      if (pid == -1)
//      {
//           perror("fork");
//           exit(EXIT_FAILURE);
//      }

//      // Child process
//      if (pid == 0)
//      {
//           count_unique_words(argv[1]);
//      }

//      // Parent process
//      else
//      {
//           // Wait for the child process to finish
//           int status;
//           waitpid(pid, &status, 0);
//      }

//      return 0;
// }