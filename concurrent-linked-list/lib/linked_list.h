#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include <thread>
#include <mutex>

struct node {
  int data;
  struct node * next_node;
};

class Linked_list {

  private:
  int m_length;
  int m_counter;
  struct node * m_head;
  struct node * m_chain;

  public:
  Linked_list();
  struct node * create_node(int data);
  void insert(int data);
  struct node * pop();
  bool search(int target);
  void display();

};

#endif
