#include "gtest/gtest.h"
#include<iostream>
#include<string>
using namespace std;

string countAndSay(int n) {
  std:: string t = "";
  if(n == 1) {
    t = "one";
  }
  return t;
}

//// TEST CASES ////////
TEST(CountAndSayTest, Negative) {
  EXPECT_EQ("one", countAndSay(1));
}

TEST(CountAndSayTest, Zero) {
  EXPECT_EQ("zero", countAndSay(0));
}

TEST(CountAndSayTest, Positive) {
  EXPECT_EQ("one 1", countAndSay(11));
}

