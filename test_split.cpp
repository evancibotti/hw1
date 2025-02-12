/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char* argv[])
{
  // create nodes
  Node* evens = nullptr;
  Node* odds = nullptr;
  Node* original = new Node(1, new Node(2, new Node(3, new Node(4, new Node))));

  // call function
  split(original, odds, evens)

  for(Node* traverse = evens; traverse != nullptr; traverse = traverse->next){
    std::cout << traverse->value;
  }

  std::cout << std::endl:

  for(Node* traverse = odds; traverse != nullptr; traverse = traverse->next){
    std::cout << traverse->value;
  }

  std::cout << std::endl:
  
}
