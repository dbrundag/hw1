/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;

#include "ulliststr.h"


int main(int argc, char* argv[])
{
	ULListStr dat;
	const std::string str1 = "seven";
	const std::string str2 = "nine";
	const std::string str3 = "two";

	dat.push_back(str1);
	dat.push_back(str3);
	dat.push_front(str2);
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
	// cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
	cout << dat.get(0) << " " << dat.get(1) << endl;

	// prints: 8 7 9
	// cout << dat.size() << end;  // prints 3 since there are 3 strings stored

  return 0;
}
