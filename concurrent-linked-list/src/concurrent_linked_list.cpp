#include "../lib/concurrent_linked_list.h"

Concurrent_linked_list::Concurrent_linked_list(): m_counter(0x0)
{ /* */ }

void Concurrent_linked_list::concurrent_insert(int data) {
  std::lock_guard<std::mutex> lock(m_mutex);
  insert(data);
}

void Concurrent_linked_list::concurrent_search(int data) {
  search(data);
}

void Concurrent_linked_list::concurrent_remove(int position) {
  std::lock_guard<std::mutex> lock(m_mutex);
  remove(position);
}

void Concurrent_linked_list::set_insertion_threads_number(int number) {
  m_insertion_threads_number = number;
  m_threads_I = new std::thread [m_insertion_threads_number];
}

void Concurrent_linked_list::set_remotion_threads_number(int number) {
  m_remotion_threads_number = number;
  m_threads_R = new std::thread [m_remotion_threads_number];
}

void Concurrent_linked_list::set_search_threads_number(int number) {
  m_search_threads_number = number;
  m_threads_B = new std::thread [m_search_threads_number];
}

void Concurrent_linked_list::run() {
  int i;
  int j;

  for (i = 0x0; i < m_insertion_threads_number; i++) {
    m_threads_I[i]  = std::thread(&Concurrent_linked_list::concurrent_insert, this, m_counter++);
  }

  for (j = 0x0; j < m_insertion_threads_number; j++) {
    m_threads_I[j].join();
  }

  for (i = 0x0; i < m_remotion_threads_number; i++) {
    m_threads_R[i]  = std::thread(&Concurrent_linked_list::concurrent_remove, this, 0x0);
  }

  for (j = 0x0; j < m_remotion_threads_number; j++) {
    m_threads_R[j].join();
  }

  for (i = 0x0; i < m_search_threads_number; i++) {
    m_threads_B[i]  = std::thread(&Concurrent_linked_list::concurrent_search, this, m_counter--);
  }

  for (j = 0x0; j < m_search_threads_number; j++) {
    m_threads_B[j].join();
  }

}
