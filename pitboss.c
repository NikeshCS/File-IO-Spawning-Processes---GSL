#include <stdio.h>  /* printf */
#include <getopt.h> /* getopt */
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

#define MAX 100

//struct definition
struct rec
{
  int per; 
  int trials; 
  float suc; 
  float fail;
};

int main(int argc, char *argv[])
{
  char *var1;
  char *var2;
  int opt;
  char *userfile = argv[3];
  int counter;
  while ((opt = getopt(argc, argv, "-:p:")) != -1) 
  {
    switch (opt) 
     { 
      case 'p':
      var1 = optarg;
      break;
      case 1:
      var2 = optarg;
      int percint = atoi(argv[2]);
      struct rec structs[MAX];
      int i = 1;
      int index;
      
      //File for reading
      FILE *file;
      file = (fopen(userfile, "rb"));
      
      //Read messages to user
      printf("\nReading results from %s ...\n\n", var2);
      printf("Checking results for -p = %d ...\n\n", percint);
      
      //Parse loop
      while(fscanf(file, "%d%d%f%f", &structs[i].per, &structs[i].trials,
                                   &structs[i].suc, &structs[i].fail)!= EOF)
      {
        if(structs[i].per == percint)
        {
          //print to user the results
          printf("Found %d trials\n\n", structs[i].trials);
          printf("Success - %.1f%\n", structs[i].suc);
          printf("Failure - %.1f%\n\n", structs[i].fail);
         }
      }
      
      //close file
      fclose(file);
      break;
    }
  }
    return 0;
}    

