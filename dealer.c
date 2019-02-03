#include <stdio.h>  /* printf */
#include <getopt.h> /* getopt */
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc, char *argv[])
{
  //variables
  int opt;
  char *var1;
  char *var2;
  int i, j;
  int status;
  int i2;
  int sig;
  pid_t pid;
  float sc;
  float fc;
  float s, f;
  int flag = 0;
  int vlag = 0;
  int success, failure;
  
  //Getopts arguments
  while ((opt = getopt(argc, argv, "-:o:p:v:")) != -1) 
  {
     switch (opt) 
     { 
      case 'p':
      var1 = optarg;
      break;
      
      case 'v': 
      var1 = optarg;
      int i3 = atoi(var1);
      for(i=0;i<i3;i++)
      {
        pid = fork();
        if(pid < 0)
        {
          perror("Fork has failed");
          exit(1);
        }
        if(pid == 0)
        {
          execl("./hand", "hand", argv[1], argv[2], NULL);
          exit(1);
        }
        else 
        {
        }
        if(WIFEXITED(status))
          {
            wait(&status);
            int es = WEXITSTATUS(status);
            if(es == 1)
            {
              printf("PID %d returned success \n",pid); 
              sc++;
            }
            else
            {
              printf("PID %d returned failure \n",pid);
              fc++;
            }
          }
        }

        s = (sc/i3) * 100;
        f = 100 - s;
        success = (int)(s+.5);
        failure = (int) (f + .5);
        printf("Created %d processes.\n", i3);
        printf("Success - %d%\n", success);
        printf("Failure - %d%\n", failure);
        
       break;
     
      case 1:
      
      var1 = optarg;
      i3 = atoi(var1);
     for(i=0;i<i3;i++)
      {
        if(pid < 0)
        {
          perror("Fork has failed");
          exit(1);
        }
        if( fork() == 0)
        {
          execl("./hand", "hand", argv[1], argv[2], NULL);
          exit(1);
        }
        else 
        {
        }
        if(WIFEXITED(status))
          {
            wait(&status);
            int es = WEXITSTATUS(status);
            if(es == 1)
            {
              sc++;
            }
            else
            {
             fc++;
            }
          }
        }
            
        s = (sc/i3) * 100;
        f = 100 - s;
        printf("\n");
        printf("Created %d processes.\n", i3);
        printf("Success - %.1f%\n", s);
        printf("Failure - %.1f%\n", f);
        if(flag ==1)
        {
          FILE *ptr_myfile;
          char *file = argv[4];
          int percentage = 0;
          percentage = atoi(argv[2]);
          int numOfTrials = atoi(argv[5]);
         ptr_myfile=(fopen(file, "ab"));
          fprintf(ptr_myfile, "%d %d %.1f %.1f\n" ,percentage, numOfTrials, s, f);   
          	fclose(ptr_myfile);
           printf("\nResults were written to %s\n", file);
         }
      break;
      
      //O FLAG FOR FILENAME
      case 'o':
      flag = 1;
      
      break;
      
      default:
      fprintf(stderr, "Usage:  ./dealer [-p num num ] or ./dealer [-p num -v num]\n");
      return EXIT_FAILURE;
     }
  }
  
  
  return 0;
}





