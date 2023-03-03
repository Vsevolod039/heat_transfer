//
//  barrier.hpp
//  build
//
//  Created by Vsevolod Vinnitskiy on 03.03.2023.
//

#ifdef __APPLE__

#ifndef PTHREAD_BARRIER_H_
#define PTHREAD_BARRIER_H_

#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef int pthread_barrierattr_t;
struct pthread_barrier_t
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int tripCount;
};


int pthread_barrier_init (pthread_barrier_t *barrier, const pthread_barrierattr_t *attr, unsigned int count);

int pthread_barrier_destroy (pthread_barrier_t *barrier);

int pthread_barrier_wait (pthread_barrier_t *barrier);

#endif // PTHREAD_BARRIER_H_
#endif // __APPLE__
