#include <iostream>

  struct node {
  int data;
  struct node * next_node;
};

/* add templte */
class Linked_list {

  private:
  struct node * m_head;
  struct node * m_chain;
  /* threads do tipo B realizam buscas na list
     threads do tipo I realizam isercao de itens no final da lista
     threads do tipo R reliza remocao no final da lista */
  /* struct threads */
  int m_length;

  public:
  Linked_list();
  struct node * create_node(int data);
  void add(int data);
  struct node * pop();
  bool search(int target);
  void display();

};


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



int main (void) {

  return 0x0;
}
