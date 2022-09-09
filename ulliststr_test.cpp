/* Write your test code for the ULListStr in this file */
#include <iostream>
#include "ulliststr.h"


int main(int argc, char* argv[])
{
  ULListStr test;
  ULListStr other;
  
  //push_front and push_back on an empty list
  test.push_front("1");
  other.push_back("9");

  //push_front and push_back on an existing list
  test.push_back("2");
  other.push_front("8");

  //See if output matches test{12} and other{89}
  std::cout << test.get(0) << " - " <<  test.get(1) << std::endl;
  std::cout << other.get(0) << " - " << other.get(1) << std::endl;

  return 0;
}
