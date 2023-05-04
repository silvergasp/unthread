#ifndef UNTHREAD_TEST
#define UNTHREAD_TEST

// Utility library for Unthread. This header can be used with or without the
// Unthread library itself.
//
// unthread_yield: yields only when using Unthread.
// unthread_test: returns true when using Unhtread and false otherwise.

#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef UNTHREAD
void unthread_yield() { pthread_yield(); }

static inline bool unthread_test() { return true; }

void unthread_set_entropy_source(uint8_t buffer, size_t size);
#else
static inline void unthread_yield() {}

static inline bool unthread_test() { return false; }

void unthread_set_entropy_source(uint8_t buffer, size_t size);
#endif

#endif