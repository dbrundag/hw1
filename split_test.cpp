#include "split.h"
#include <iostream>
using namespace std;

int main(){

	struct Node* head;
	struct Node* one = (struct Node*)malloc(1 * sizeof(struct Node));
	struct Node* two = (struct Node*)malloc(1 * sizeof(struct Node));
	struct Node* three = (struct Node*)malloc(1 * sizeof(struct Node));
	struct Node* four = (struct Node*)malloc(1 * sizeof(struct Node));
	struct Node* five = (struct Node*)malloc(1 * sizeof(struct Node));
	struct Node* six = (struct Node*)malloc(1 * sizeof(struct Node));
	struct Node* seven = (struct Node*)malloc(1 * sizeof(struct Node));

 //define and connect nodes
	one->value = 1;
	one->next = two;
	two->value = 2;
	two->next = three;
	three->value = 3;
	three->next = four;
	four->value = 4;
	four->next = five;
	five->value = 5;
	five->next = six;
	six->value = 6;
	six->next = seven;
	seven->value = 7;
	seven->next = NULL;

//  /* TEST THAT MY INITIAL LINKED LIST IS CONNECTED */
//  	std::cout << "TEST 1:" << std::endl;
// 	head = one;

// 	while(head != NULL){
// 		std::cout<< head->value <<std::endl;
// 		head = head->next;
// 	}

/* TEST SPLIT FUNCTION */
	std::cout << "TEST 2:" << std::endl;
	head = one;

	struct Node* evens;
	struct Node* odds;

	split(head, odds, evens);

	if(head == NULL){
		std::cout << "in has been set to NULL" <<std::endl;
	}

	head = odds;
	std::cout<<"Odd numbers"<<std::endl;
	while(head != NULL){
		std::cout<< head->value <<std::endl;
		Node* tmp = head;
		head = head->next;
		free(tmp);
	}

	head = evens;
	std::cout<<"Even numbers"<<std::endl;
	while(head != NULL){
		std::cout<< head->value <<std::endl;
		Node* tmp = head;
		head = head->next;
		free (tmp);
	}

	free(head);
	// free(evens);
	// free(odds);

	return 0;
}