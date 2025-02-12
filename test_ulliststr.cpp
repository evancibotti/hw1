#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr test;
  // add to front when empty
  test.push_front("1");
  // add to front when not empty
  test.push_front("2");
  // return front
  std::cout << test.front() << std::endl;
  // remove from front
  test.pop_front();
  // remove again
  test.pop_back();

  // add to back when empty
  test.push_back("1");
  // add to front when not empty
  test.push_back("2");
  // return back
  std::cout << test.back() << std::endl;
  // remove from back
  test.pop_back();
  // remove again
  test.pop_back();

  std::cout << "Passed Tests." << std::endl;

}
