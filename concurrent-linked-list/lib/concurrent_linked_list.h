#ifndef __CONCURRENT_LINKED_LIST__
#define __CONCURRENT_LINKED_LIST__

#include <iostream>
#include <thread>
#include <mutex>
#include "../lib/linked_list.h"

class Concurrent_linked_list: public Linked_list {

  private:
  int m_counter;
  std::mutex m_mutex;
  std::thread * m_threads_B;
  std::thread * m_threads_I;
  std::thread * m_threads_R;

  int m_search_threads_number;
  int m_insertion_threads_number;
  int m_remotion_threads_number;

  public:
  Concurrent_linked_list();
  void concurrent_insert(int data);
  void concurrent_search(int data);
  void concurrent_remove(int postion);
  void set_insertion_threads_number(int number);
  void set_remotion_threads_number(int number);
  void set_search_threads_number(int number);
  void run();

};

#endif
