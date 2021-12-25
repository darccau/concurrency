#include <iostream>

  /* add templte */
  class Linked_list {

  privite:
  int * m_head;
  int * m_linked_list;
  int m_length;

  public:
  void create_node(int data);
  void create_linked_list();
  void add(int data);
  int pop();
  search(int target);
  void display(int * linked_list);

};

  void Linked_list::create_node();
  void Linked_list::create_linked_list();
  void Linked_list::add();
  void Linked_list::pop();
  void Linked_list::search();
  bool Linked_list::search(int target);
  void Linked_list::display();

int main (void) {

  return 0x0;
}
