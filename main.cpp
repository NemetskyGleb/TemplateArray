#include "Array.h"
#include <iostream>


int main(){
	int a[5] {5, 1, 2, 3, 4};
	ARRAY::Array temp(a, 5);
	std::cout << a;
	temp += 2;
	temp.Sorting();
	std::cout << temp;
	return 0;
}