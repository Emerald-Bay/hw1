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

#include <iostream>
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

  //Value is odd
  if (in->value % 2) {
    odds = in;
  } //Value is even
  else {
    evens = in;
  }

  //Last node in the list
  if (in->next == nullptr) {
    in = nullptr;
    return;
  }

  splitHelper(in->next, odds, evens);

  //Original list is not preserved
  in = nullptr;
}

void splitHelper(Node*& in, Node*& odds, Node*& evens) {
  bool evenFlag = true;
  bool oddFlag = true;

  //Value is odd
  if (in->value % 2) {
    if (odds == nullptr) {
      odds = in;
    }
    else {
      odds->next = in;
      oddFlag = false;
    }
  } //Value is even
  else {
    if (evens == nullptr) {
      evens = in;
    }
    else {
      evens->next = in;
      evenFlag = false;
    }
  }

  //Last node in the list
  if (in->next == nullptr) {
    if (evenFlag && evens != nullptr) {
      evens->next = nullptr;
    }

    if (oddFlag && odds != nullptr) {
      odds->next = nullptr;
    }

    return;
  }

  //Ensures first addition does not mess up later addition
  splitHelper(in->next, oddFlag ? odds : odds->next, evenFlag ? evens : evens->next);
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE