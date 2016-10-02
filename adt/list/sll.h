#ifndef StringLinkedList_included
#define StringLinkedList_included

#include "iostream"
using namespace std;

class StringNode {                        // a node in a list of strings
private:
  string elem;                            // element value
  StringNode* next;                       // next item in the list

  friend class StringLinkedList;          // provide StringLinkedList access
};

class StringLinkedList {                  // a linked list of strings
public:
  StringLinkedList();                     // empty list constructor
  ~StringLinkedList();                    // destructor
  bool empty() const;                     // is list empty?
  const string& front() const;            // get front element
  void addFront(const string& e);         // add to front of list
  void removeFront();                     // remove front item list
private:
  StringNode* head;                       // pointer to the head of list
};

	

#endif
