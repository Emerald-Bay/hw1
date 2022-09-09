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

  //See if output matches test{1 - 2 - 2} and other{8 - 9 - 2}
  std::cout << test.get(0) << " - " << test.get(1) << " - " << test.size() << std::endl;
  std::cout << other.get(0) << " - " << other.get(1) << " - " << other.size() << std::endl;

  std::cout << "----------------------------------" << std::endl;

  //Testing pop_front and pop_back on an existing list
  test.pop_front();
  other.pop_back();
  other.push_back("4");
  other.pop_front();

  //Output should be test{2} and other{4}
  std::cout << test.get(0) << std::endl;
  std::cout << other.get(0) << std::endl;

  std::cout << "----------------------------------" << std::endl;

  //Testing pop_front and pop_back on an empty list
  test.pop_front();
  other.pop_back();
  test.pop_front();
  other.pop_back();

  //Testing push_front and push_back on a full list (where it has to make a new item/node)
  test.push_front("1"); 
  test.push_front("1"); 
  test.push_front("1");
  test.push_front("1"); 
  test.push_front("1"); 
  test.push_front("1");
  test.push_front("4");

  other.push_back("8"); 
  other.push_back("8"); 
  other.push_back("8"); 
  other.push_back("8"); 
  other.push_back("8"); 
  other.push_back("5");

  //Output should be test{4 - 1 - 7} and other{8 - 5 - 6}
  std::cout << test.get(0) << " - " << test.get(1) << " - " << test.size() << std::endl;
  std::cout << other.get(4) << " - " << other.get(5) << " - " << other.size() << std::endl;

  std::cout << "----------------------------------" << std::endl;

  //Stress test for the list, having to make many new items and then keep track of them all
  for (int i = 0; i < 100; i++) {
    test.push_back("2");
    other.push_front("2");
  }

  //Output should be test{4 - 1 - 2 - 2 - 2 - 107} and other{2 - 2 - 2 - 8 - 5 - 106}
  std::cout << test.get(0) << " - " << test.get(1) << " - " << test.get(53) << " - " << test.get(105) << " - " << test.get(106) << " - " << test.size() << std::endl;
  std::cout << other.get(0) << " - " << other.get(1) << " - " << other.get(53) << " - " << other.get(104) << " - " << other.get(105) << " - " << other.size() << std::endl;

  std::cout << "----------------------------------" << std::endl;

  //Testing pop_front and pop_back to correctly delete empty items/nodes (see if valgrind gets grumpy)
  for (int i = 0; i < 100; i++) {
    test.pop_back();
    other.pop_front();
  }

  //Output should be test{4 - 1 - 7} and other{8 - 5 - 6}
  std::cout << test.get(0) << " - " << test.get(1) << " - " << test.size() << std::endl;
  std::cout << other.get(4) << " - " << other.get(5) << " - " << other.size() << std::endl;

  std::cout << "----------------------------------" << std::endl;

  //Just testing the other functions
  ULListStr rest;
  rest.push_front("1");
  rest.push_back("9");

  //Output should be rest{1 - 9 - 2}
  std::cout << rest.front() << " - " << rest.back() << " - " << rest.size() << std::endl;

  return 0;
}
