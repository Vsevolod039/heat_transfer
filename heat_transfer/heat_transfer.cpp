//
//  heat_transfer.cpp
//  ht
//
//  Created by Vsevolod Vinnitskiy on 02.03.2023.
//

#include "barrier.hpp"
#include "thread_info.hpp"

void *heat_transfer_solve (void *ptr)
{
  thread_info *a = (thread_info *) ptr;
  
  pthread_barrier_wait (a->get_barrier ());
  printf ("Hello world from %d thread\n", a->get_thread_number ());
  
  return 0;
}

