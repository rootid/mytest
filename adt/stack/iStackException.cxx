#include<iostream>
using namespace std;

class StackEmpty : public RuntimeException {

  public:
  StackEmpty(const string& err) : RuntimeException(err) {

  }
};

class StackFull : public RuntimeException {

  public:
  StackFull(const string& err) : RuntimeException(err) {

  }
};
