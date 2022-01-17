#include <iostream>
/* #include <gtest/gtest.h> */
#include "../lib/concurrent_linked_list.h"

#define INSERTION_THREADS_NUMBER 90
#define REMOTION_THREADS_NUMBER 30
#define SEARCH_THREADS_NUMBER  10

int main(int argc, char ** argv) {

  Concurrent_linked_list concurrent_linked_list;

  concurrent_linked_list.set_insertion_threads_number(INSERTION_THREADS_NUMBER);
  concurrent_linked_list.set_remotion_threads_number(REMOTION_THREADS_NUMBER);
  concurrent_linked_list.set_search_threads_number(SEARCH_THREADS_NUMBER);

  concurrent_linked_list.run();

  concurrent_linked_list.display();

  return 0x0;
}
