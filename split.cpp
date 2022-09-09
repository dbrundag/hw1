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
#include <cstddef>

#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  if(in == NULL)
  {
    return;
  }

	//in's first int can be either positive or negative.
	//But hold's same alternating pattern after first number
	if (in->value %2 == 0){
		evens = in;
		odds = in->next;
	}
	else{
		odds = in;
		evens = in->next;
	}
	//split recursively by shifting respective pointers
	reconstruct(odds, evens);
	in = NULL;
}

/* If you needed a helper function, write it here */

//split odd and even list at same rate
void reconstruct(Node*& odds, Node*& evens){
	if(odds == NULL || evens == NULL){
		return;
	}
	if(odds->next){
		odds->next = odds->next->next;
	}
	if(evens->next){
		evens->next = evens->next->next;
	}
	reconstruct(odds->next, evens->next); 
	//split until nothing to split
}
// WRITE YOUR CODE HERE