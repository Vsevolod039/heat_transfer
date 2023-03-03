//
//  thread_info.cpp
//  ht
//
//  Created by Vsevolod Vinnitskiy on 03.03.2023.
//

#include "barrier.hpp"
#include "thread_info.hpp"

thread_info::thread_info (int thread_amount, int thread_number, pthread_barrier_t *barrier)
{
  init (thread_amount, thread_number, barrier);
}

void thread_info::init (int thread_amount, int thread_number, pthread_barrier_t *barrier)
{
  m_thread_amount = thread_amount;
  m_thread_number = thread_number;
  m_barrier = barrier;
}

bool allocate_array (unsigned int size, double *array, const char *name)
{
  array = new double [size];
  if (!array)
    {
      printf ("  Usage: cannot allocate array %s of size %d\n", name, size);
      return false;
    }
  return true;
}
