/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;

#include "ulliststr.h"


int main(int argc, char* argv[])
{
	ULListStr dat;
	// std::cout << dat.front() <<std::endl;

	const std::string str1 = "one";
	const std::string str2 = "two";
	const std::string str3 = "three";
	const std::string str4 = "four";

	///////////////////////////
	/* PUSH_BACK TEST CASES */
	/////////////////////////
	std::cout << "PUSH BACK TEST CASES" << endl;

	// when ULListStr tail is NULL
	dat.push_back(str1);
	std::cout << "Should be 'one'. Get(0) returns: " << dat.get(0) << std::endl;
	//when at least one element is in tail
	dat.push_back(str2);
	std::cout << "Should be 'two'. Get(1) returns: " << dat.get(1) << std::endl;
	//when needs to create new item to expand right --> head & tail different. str4 in tail
	dat.clear();
	for(int i=0; i < ARRSIZE; i++){
		dat.push_back(str3);
	}
	dat.push_back(str4);
	std::cout << "Should be 'four'. Get(10) returns: " << dat.get(10) << std::endl;
	std::cout << "Size should be 11. size() returns: " << dat.size() <<std::endl;

	dat.clear();

	////////////////////////////
	/* PUSH_FRONT TEST CASES */
  //////////////////////////

	std::cout << "PUSH FRONT TEST CASES" << endl;

	// when ULListStr head is NULL
	dat.push_front(str1);
	std::cout << "Should be 'one'. Get(0) returns: " << dat.get(0) << std::endl;
	//when at least one element is in head
	dat.push_front(str2);
	std::cout << "Should be 'two'. Get(1) returns: " << dat.get(1) << std::endl;
	//when needs to create new item to expand left --> head & tail different. str4 in head
	dat.clear();
	for(int i=0; i < ARRSIZE; i++){
		dat.push_front(str3);
	}
	dat.push_front(str4);
	std::cout << "Should be 'four'. Get(0) returns: " << dat.get(0) << std::endl;
	std::cout << "Size should be 11. size() returns: " << dat.size() <<std::endl;

	dat.clear();

	//////////////////////////
	/* POP_BACK TEST CASES */
	/////////////////////////

	std::cout << "POP FRONT TEST CASES" <<endl;
	//when attempting to pop_back of empty list -->works if doesn't crash
	dat.pop_back();
	std::cout << "Success. Did not segfault." << endl;
	//when attempting to pop only item from list -->head and tail should be null. 
	dat.push_back(str1);
	dat.pop_back();
	//should return null for front and null for back. affirming ^^^.
	// --> will throw error and abort program as expected std::cout << dat.front() << dat.back() << endl;
	
	//when attempting to pop item from list with multiple elements in list 
	dat.push_back(str1);
	dat.push_back(str2);
	dat.pop_back();
	std::cout << "Size should be 1. Size is: " << dat.size() << endl;


	std::cout << "POP FRONT TEST CASES" <<endl;
	//when attempting to pop_front of empty list -->works if doesn't crash
	dat.pop_front();
	std::cout << "Success. Did not segfault." << endl;
	//when attempting to pop only item from list -->head and tail should be null. 
	dat.push_back(str1);
	dat.pop_front();
	//should return null for front and null for back. affirming ^^^.
	// --> will throw error and abort program as expected std::cout << dat.front() << dat.back() << endl;

	//when attempting to pop item from list with multiple elements in list 
	dat.push_back(str1);
	dat.push_back(str2);
	dat.pop_front();
	std::cout << "Size should be 1. Size is: " << dat.size() << endl;
	dat.clear();

	/////////////
	/* FRONT TEST CASE */
	//////////////
	dat.push_front(str1);
	std::cout << "Front should be 'one'. Front is " << dat.front() << std::endl;

	/////////////
	/* BACK TEST CASE */
	//////////////
	dat.push_front(str2);
	std::cout << "Back should be 'one'. Front is " << dat.back() << std::endl;




	// //when ULListStr head is NULL
	// dat.push_front(str1);
	// //when at least one element is in head
	// dat.push_front(str2);
	// //when needs to create new item to expand right
	// dat.clear();
	// for(int i=0; i < ARRSIZE; i++){
	// 	dat.push_back(str3);
	// }
	// dat.push_back(str4);

	

	// std::cout << dat.front() << std::endl;
	// std::cout << dat.back() << std::endl;
	// std::cout << dat.get(2)  << std::endl;
	// // << " " << dat.get(1) << " " << dat.get(2) <<
	// dat.pop_front();
	// dat.pop_front();
	// dat.pop_front();

	// dat.pop_back();
	// dat.pop_back();
	// dat.pop_back();
	// std::cout << dat.back() << std::endl;

	// dat.push_back(str1);
	// //dat.push_front(8);
	// dat.push_back(str2);
	// dat.push_front(str3);
	// dat.push_back(str1);
	// dat.push_back(str2);
	// dat.push_back(str1);
	// dat.push_back(str2);
	// dat.push_back(str1);
	// dat.push_back(str2);	
	// dat.push_back(str1);
	// dat.push_back(str2);
	// dat.push_back(str1);
	// dat.push_back(str1);
	// dat.push_back(str1);
	// dat.push_front(str3);


	//dat.push_back(str3);
	//cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
	//cout << dat.get(0) << " " << dat.get(1) << endl;

	// prints: 8 7 9
	// cout << dat.size() << end;  // prints 3 since there are 3 strings stored

  return 0;
}
