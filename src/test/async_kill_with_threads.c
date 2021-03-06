/* -*- Mode: C; tab-width: 8; c-basic-offset: 2; indent-tabs-mode: nil; -*- */

#include "rrutil.h"

static void* start_thread(__attribute__((unused)) void* p) {
  atomic_puts("ready");
  sleep(1000);
  return NULL;
}

int main(void) {
  pthread_t thread;

  pthread_create(&thread, NULL, start_thread, NULL);
  atomic_puts("EXIT-SUCCESS");
  sleep(1000);
  return 0;
}
