#include <iostream>
#include <thread>
#include <mutex>

  struct node {
  int data;
  struct node * next_node;
};

/* insert templte */
class Linked_list {

  private:
  struct node * m_head;
  struct node * m_chain;
  std::thread * m_threads_B;
  std::thread * m_threads_I;
  std::thread * m_threads_R;

  int m_length;

  public:
  Linked_list(int thread_B_size, int thread_I_size, int threads_R_size);
  struct node * create_node(int data);
  void insert(int data);
  struct node * pop();
  bool search(int target);
  void display();
  void sample(int thread);

};

void Linked_list::sample(int thread) {
  std::cout << "hello im - " << thread << std::endl;
}

Linked_list::Linked_list(int threads_B_size, int threads_I_size, int threads_R_size) {
  int thread;
  m_head = create_node(0x0);
  m_chain = NULL;
  m_head->next_node = m_chain;


  m_threads_B = new std::thread [threads_B_size];
  m_threads_I = new std::thread [threads_I_size];
  m_threads_R = new std::thread [threads_R_size];

  for (thread = 0x0; thread < threads_I_size; thread++) {
    m_threads_I[thread] = std::thread(&Linked_list::insert, this, thread);
  }
  for (thread = 0x0; thread < threads_I_size; thread++) {
    m_threads_I[thread].join();
  }

  for (thread = 0x0; thread < threads_B_size; thread++) {
    m_threads_I[thread] = std::thread(&Linked_list::search, this, thread);
  }
  for (thread = 0x0; thread < threads_B_size; thread++) {
    m_threads_I[thread].join();
  }

  for (thread = 0x0; thread < threads_R_size; thread++) {
    m_threads_I[thread] = std::thread(&Linked_list::pop, this);
  }
  for (thread = 0x0; thread < threads_R_size; thread++) {
    m_threads_I[thread].join();
  }

}

struct node * Linked_list::create_node(int data) {
  struct node * new_node = new struct node;
  new_node->data = data;
  new_node->next_node = NULL;

  return new_node;
}

void Linked_list::insert(int data) {
  struct node * new_node = create_node(data);

  if (m_chain == NULL) {
    m_chain = new_node;
    m_head->next_node = m_chain;
    return;
  }

  m_chain = m_head->next_node;
  while (m_chain->next_node != NULL) {
    m_chain = m_chain->next_node;
  }

  m_chain->next_node = new_node;
  m_length++;
}

struct node * Linked_list::pop() {
  struct node * removed_node;

  m_chain = m_head->next_node;

  while (m_chain->next_node->next_node) {
    m_chain = m_chain->next_node;
  }

  removed_node = m_chain->next_node;

  delete m_chain->next_node;
  m_chain->next_node = NULL;

  m_length--;

  return removed_node;
}

bool Linked_list::search(int target) {
  m_chain = m_head->next_node;

  while (m_chain) {
    if (m_chain->data == target) {
      return true;
    }
    m_chain = m_chain->next_node;
  }

return false;
}

void Linked_list::display() {
  m_chain = m_head->next_node;

  while (m_chain) {
    std::cout << "[" << m_chain->data << "]" << std::endl;
    m_chain = m_chain->next_node;
  }
}



int main (int argc, char ** argv) {
  int threads_B_number;
  int threads_I_number;
  int threads_R_number;

  threads_B_number = atoi(argv[0x1]);
  threads_I_number = atoi(argv[0x2]);
  threads_R_number = atoi(argv[0x3]);

  Linked_list list = Linked_list(threads_B_number, threads_I_number, threads_R_number);

  list.display();

  return 0x0;
}
