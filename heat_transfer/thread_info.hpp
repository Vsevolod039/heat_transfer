//
//  thread_info.hpp
//  ht
//
//  Created by Vsevolod Vinnitskiy on 03.03.2023.
//

#ifndef thread_info_hpp
#define thread_info_hpp

struct pthread_barrier_t;

class thread_info
{
private:
  int m_thread_amount = 0;
  int m_thread_number = 0;
  pthread_barrier_t *m_barrier = nullptr;
public:
  thread_info () = default;
  thread_info (int thread_amount, int thread_number, pthread_barrier_t *barrier);
  void init (int thread_amount, int thread_number, pthread_barrier_t *barrier);
  
  int get_thread_amount () { return m_thread_amount; }
  int get_thread_number () { return m_thread_number; }
  pthread_barrier_t * get_barrier () { return m_barrier; }
  
};

#endif /* thread_info_hpp */

bool allocate_array (unsigned int size, double *array, const char *name);
