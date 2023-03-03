//
//  main.cpp
//  ht
//
//  Created by Vsevolod Vinnitskiy on 02.03.2023.
//

#define __APPLE__ 1 // Run program on MacOs

#include "barrier.hpp"
#include "heat_transfer.hpp"
#include "thread_info.hpp"


int main (int argc, char ** argv)
{
  const double a = 10.;
  const double b = 5.;
  
  const int nx = 100;
  const int ny = 10;
  
  const double T = 1;
  const int nt = 10;
  
  const int thr_amount = 2;
  
  double *matrix = nullptr;
  double *rhs = nullptr;
  
  if (!allocate_array ((nx + 1) * (ny + 1) * (nx + 1) * (ny + 1), matrix, "matrix"))
    return -1;
  
  if (!allocate_array ((nx + 1) * (ny + 1), rhs, "rhs"))
    {
      delete [] matrix;
      return -2;
    }
  
  pthread_t *thr = new pthread_t [thr_amount];
  pthread_barrier_t barrier_calc;
  pthread_barrier_init (&barrier_calc, NULL, thr_amount);
  
  for (int iter = 0; iter < thr_amount; iter ++)
    {
      thread_info info (thr_amount, iter, &barrier_calc);
      pthread_create (thr + iter, 0, heat_transfer_solve, &info);
    }
  
  pthread_barrier_destroy (&barrier_calc);
  
  delete [] matrix;
  delete [] rhs;
  return 0;
}
