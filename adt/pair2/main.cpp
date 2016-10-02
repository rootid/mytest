#include "my-pair.h"
#include <iostream>
using namespace std;

int main() {
  MyPair<int,int> p;
  p.setFirst(12);
  p.setSecond(13);

  cout <<  " first " <<  p.getFirst() << "|"  << p.getSecond() << endl ;
}
