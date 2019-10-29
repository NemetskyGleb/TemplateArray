#include <iostream>
#include "Array.h"
const int N = 5;

int main(){
	double *temp2 = new double[N] { 1.1 , 0, 3.2, 2 , 3.4}; 
	/* Testing methods of class Array*/
	Array<double> arr2(temp2, N);
	Array<double> arr3;
	std::cout << "Testing methods of class Array: " << std::endl;
	std::cout << "double Array2 = " << arr2;
	std::cout << "Empty Array3 =  " << arr3;
	arr3 = arr2;
	std::cout << "Empty Array3 = Array1 = " << arr3;
	std::cout << "Array3[0] = " << arr3[0] << std::endl;
	std::cout << "Position of number 2 in Array3 : " << arr3.Find(2) << std::endl;
	arr3 += 10;
	std::cout << "Add number 10 in Array3: " << arr3;
	arr3 += arr2;
	std::cout << "Add Array2 to Array3 : " << arr3;
	arr3 = arr3 - 1.1;
	std::cout << "Delete number 1.1 from Array3: " << arr3;
	std::cout.setf(std::ios::boolalpha);
	bool res = (arr3 == arr2);
	std::cout << "Is Array3 = Array2 - " << res << std::endl;
	res = (arr3 != arr2);
	std::cout << "Is Array3 != Array2 - " << res << std::endl;
	std::cout << "Max index in Array3: " << arr3.Max() << std::endl;
	std::cout << "Min index in Array3 " << arr3.Min() << std::endl;
	arr3.Sorting();
	std::cout << "Sort Array3: " << arr3;;
	delete[] temp2;
	std::cin.get();
	return 0;
}