#ifndef CLL_included
#define CLL_included 

#include<iostream>
#include<string>

class CircleList;
typedef std::string Elem;                       // element type
class CNode {                              // circularly linked list node
private:
  Elem elem;                               // linked list element value
  CNode* next;                             // next item in the list

  friend class CircleList;                 // provide CircleList access
};


class CircleList {                         // a circularly linked list
public:
  CircleList();                            // constructor
  ~CircleList();                           // destructor
  bool empty() const;                      // is list empty?
  const Elem& front() const;               // element at cursor
  const Elem& back() const;                // element following cursor
  void advance();                          // advance cursor
  void add(const Elem& e);                 // add after cursor
  void remove();                           // remove node after cursor
private:
   CNode* cursor;                          // the cursor
};

CircleList::CircleList()                   // constructor
  : cursor(NULL) { }
CircleList::~CircleList()                  // destructor
  { while (!empty()) remove(); }


bool CircleList::empty() const             // is list empty?
  { return cursor == NULL; }
const Elem& CircleList::back() const       // element at cursor
  { return cursor->elem; }
const Elem& CircleList::front() const      // element following cursor
  { return cursor->next->elem; }
void CircleList::advance()                 // advance cursor
  { cursor = cursor->next; }


void CircleList::add(const Elem& e)  {  // add after cursor
  CNode* v = new CNode;                 // create a new node
  v->elem = e;
  if (cursor == NULL) {                 // list is empty?
     v->next = v;                       // v points to itself
     cursor = v;                        // cursor points to v
  }
  else {                                // list is nonempty?
     v->next = cursor->next;            // link in v after cursor
     cursor->next = v;
  }
}


void CircleList::remove() {              // remove node after cursor
  CNode* old = cursor-> next;            // the node being removed
  if (old == cursor)                     // removing the only node?
     cursor = NULL;                      // list is now empty
  else
     cursor->next = old-> next;          // link out the old node
  delete old;                            // delete the old node
}


int main() {
  CircleList playList;             // []
  playList.add("Arjit sigh");    // [Arjit sigh*]
  playList.add("A R Rehman");        // [A R Rehman, Arjit sigh*]
  playList.add("Jagjit Singh");     // [Jagjit Singh, A R Rehman, Arjit sigh*]

  playList.advance();              // [A R Rehman, Arjit sigh, Jagjit Singh*]
  playList.advance();              // [Arjit sigh, Jagjit Singh, A R Rehman*]
  playList.remove();               // [Jagjit Singh, A R Rehman*]
  playList.add("Ajay-Atul");   // [Ajay-Atul, Jagjit Singh, A R Rehman*]
  std::cout << playList.front() << std::endl;
  return 0;
}


#endif /* ifndef CLL_included */
