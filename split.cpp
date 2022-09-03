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
void split(Node*& in, Node*& odds, Node*& evens);
void splitHelper(Node*& in, Node*& odds, Node*& evens);

//Broken into two for added efficiency, limited edge case testing
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  //Empty linked list
  if (in == nullptr) {
    return;
  }

  bool evenFlag = false;

  if (in->value % 2) {
    odds->next = in;
  } //Value is even
  else {
    evens->next = in;
    evenFlag = true;
  }

  //Original list is not preserved
  in = nullptr;

  //Last node in the list
  if (in->next == nullptr) {
    return;
  }

  return splitHelper(in->next, evenFlag ? odds : odds->next, evenFlag ? evens->next : evens);
}

void splitHelper(Node*& in, Node*& odds, Node*& evens) {
  bool evenFlag = false;

  //Value is odd
  if (in->value % 2) {
    odds->next = in;
  } //Value is even
  else {
    evens->next = in;
    evenFlag = true;
  }

  //Last node in the list
  if (in->next == nullptr) {
    return;
  }

  //Makes sure the list that was added to advances down the chain
  return splitHelper(in->next, evenFlag ? odds : odds->next, evenFlag ? evens->next : evens);
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE