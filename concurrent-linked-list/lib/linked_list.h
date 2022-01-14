#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>

struct node {
  int data;
  struct node * next_node;
};

class Linked_list {

  public:
  int m_length;
  int m_counter;
  struct node * m_head;
  struct node * m_chain;

  Linked_list();
  struct node * create_node(int data);
  void insert(int data);
  void remove(int position);
  bool search(int target);
  void display();
};

#endif

