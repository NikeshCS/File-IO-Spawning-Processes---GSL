#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
int main (int argc, char *argv[])
{
  const gsl_rng_type * T;
  gsl_rng * r;
  gsl_rng_env_setup();
 
  int numoftrials;
  T = gsl_rng_default;
  r = gsl_rng_alloc (T);
  struct timeval timev;
  gettimeofday(&timev, 0);
  unsigned long gslSeed = timev.tv_sec + timev.tv_usec;
  gsl_rng_set(r, gslSeed);

    int u = gsl_rng_get (r);
    int h = abs(u%100);
    int i = atoi(argv[2]);
    
    //printf ("Number of random num = %d\n Passed Number = %d\n", h, i);
  
    if (h <= i)
    {
      return 1;
    }
    else
    {

      return 0;
    }
  gsl_rng_free (r);

}