/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // If the in list is empty just return
  if(in == nullptr){
    return;
  }

  // Save the next node for recursive calls
  Node* followingnode = in->next;

  // If the value is odd
  if(in->value % 2 == 1){
    // assign node to odds  
    odds = in;
    // disconnect it from the list
    odds->next = nullptr;
    // recusive call back to the function
    split(followingnode, odds->next, evens);
  // If the value is even
  } else {
    // assign node to evens
    evens = in;
    // disconnect it from the list
    evens->next = nullptr;
    // recursive call back to the function
    split(followingnode, odds, evens->next);
  }
  
  // make sure no memory leaks occurs
  in = nullptr;
}

/* If you needed a helper function, write it here */
