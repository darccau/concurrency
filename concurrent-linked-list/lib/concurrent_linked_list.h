#ifndef __CONCURRENT_LINKED_LIST__
#define __CONCURRENT_LINKED_LIST__

#include <iostream>
#include <thread>
#include <mutex>
#include "../lib/linked_list.h"

class Concurrent_linked_list: public Linked_list {

  private:
  std::mutex m_mutex;
  std::thread * m_threads_B;
  std::thread * m_threads_I;
  std::thread * m_threads_R;

  public:
  Concurrent_linked_list(int b_threads_size, int i_threads_size, int r_threads_size);
  void concurrent_insert(int target);
  void concurrent_search(int target);
  void concurrent_remove(int postion);

};

#endif
