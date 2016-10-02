#include "istackException.h"

template <typename E>
class Stack {                                // an interface for a stack
public:
  int size() const;                          // number of items in stack
  bool empty() const;                        // is the stack empty?
  const E& top() const throw(StackEmpty);    // the top element
  void push(const E& e);                     // push x onto the stack
  void pop() throw(StackEmpty);              // remove the top element
};

