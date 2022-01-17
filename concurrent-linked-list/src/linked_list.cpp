#include "../lib/linked_list.h"

Linked_list::Linked_list() {
  m_length = 0x0;
  m_counter = 0x0;
  m_head = create_node(0x0);
  m_chain = NULL;
}

struct node * Linked_list::create_node(int data) {
  struct node * new_node = new struct node;
  new_node->data = data;
  new_node->next_node = NULL;

  return new_node;
}

void Linked_list::insert(int data) {
  m_chain = m_head->next_node;

  struct node * new_node = create_node(data);

  if (m_chain == NULL) {
    m_chain = new_node;
    m_head->next_node = m_chain;
    return;
  }

  while (m_chain->next_node != NULL) {
    m_chain = m_chain->next_node;
  }

  m_chain->next_node = new_node;
  m_length++;
}

void Linked_list::remove(int position) {
  int i;
  struct node * link;
  m_chain = m_head->next_node;

  if (m_chain == NULL) {
    return;
  }

  if (position == 0x0) {
    link = m_chain->next_node;
    delete m_chain;
    m_chain = link;
    m_head->next_node = m_chain;
    return;
  }

  for (i = 0x0; i < (position - 0x1) && m_head->next_node; i++) {
    m_chain = m_chain->next_node;
  }

  if (m_chain == NULL || m_chain->next_node == NULL) {
    return;
  }

  link = m_chain->next_node->next_node;
  delete m_chain->next_node;
  m_chain->next_node = link;

  m_length--;
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
    std::cout << "[" << m_chain->data << "]";
    m_chain = m_chain->next_node;
  }
  std::cout << std::endl;
}

