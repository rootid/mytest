#include<iostream>
using namespace std;

class StackEmpty : public RuntimeException {
public:
  StackEmpty(const string& err) : RuntimeException(err) {

  }

  StackFull(const string& err) : RuntimeException(err) {

  }

};
