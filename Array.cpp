#include "Array.h"
namespace ARRAY{
Array::Array(){
	a = new int[1];
	int n = 1;
}
Array::Array(int m){
		a = new int[m];
		n = m;
	}
Array::Array (int *x , int m){
	n = m;
	a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = x[i];
	}
}

Array::Array(const Array& T){
	n = T.n;
	a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = T.a[i];
	}
}
Array& Array::operator=(const Array& T){
	if(this != &T){
		if(n != T.n){
			delete[] a;
			n = T.n;
			a = new int[n];
		}
		for (int i = 0; i < n; ++i)
		{
			a[i] = T.a[i];
		}
	}
	return *this;
}
Array::~Array(){
	delete[] a;
}
int& Array::operator[](int pos){
	if (pos < 0 || pos > n){
		std::cout << "Incorrect position. Return a[0]\n";
		return a[0];
	}
	return a[pos];
}
Array Array::operator+(const Array& T){
	int m = n + T.n;
	Array temp(m);
	for (int i = 0; i < n; i++){
		temp.a[i] = a[i];
	}
	for(int i = n, k = 0; i < m; i++, k++){
		temp.a[i] = T.a[k];
	}
	return temp;
}
Array& Array::operator+=(const Array& T){
	return *this = *this + T;
}
Array& Array::operator+=(int key){
	int *t = new int[n + 1];
	for (int i = 0; i < n; ++i)
	{
		t[i] = a[i];
	}
	t[n] = key;
	delete[] a;
	n++;
	a = t;
	return *this;
}
Array Array::operator+(int key){
	Array Res(n + 1);
	for (int i = 0; i < n; ++i)
	{
		Res.a[i] = a[i];
	}
	Res.a[n] = key;
	return Res;
}
Array Array::operator-(int key){
	Array Res(n-1);
	int k = Find(key);
	if (k >= 0){
		for(int i = 0; i < k; i++){
			Res.a[i] = a[i];
		}
		for (int i = k; i < n; i++){
			Res.a[i] = a[i+1];
		}
		return Res;
	}
	else {
		std::cout << "There is not your element in array!" << std::endl;
		return *this;
	}
}
Array& Array::operator-=(int key){
	return *this = *this - key;
}
bool Array::operator==(const Array& T){
	for (int i = 0; i < n; i++)
		if (a[i] != T.a[i])
			return false;
	return true;
}
bool Array::operator!=(const Array& T){
	for (int i = 0; i < n; i++)
		if (a[i] == T.a[i])
			return true;
	return false;
}
void Array::Sorting(){
	  int left = 0, right = n - 1;
  bool flag = true;
  while (flag && (left < right)) {
    flag = false;
    for (int i = left; i < right; ++i) {
      if (a[i] > a[i + 1]) {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
        flag = true;
      }
    }
    right--;
    for (int i = right; i > left; --i) {
      if (a[i] < a[i - 1]) {
        int temp = a[i];
        a[i] = a[i - 1];
        a[i - 1] = temp;
        flag = true;
      }
    }
    left++;
  }
}
int Array::Find(int key){
	for (int i = 0; i < n; i++){
		if (a[i] == key)
			return i;
	}
	return -1;
}
int Array::Max(){
	int maxi = 0;
	int max = a[0];
	for (int i = 1; i < n; i++){
		if (a[i] > max){
			max = a[i];
			maxi = i;
		}
	}
	return maxi;
}
int Array::Min(){
	int mini = 0;
	int min = a[0];
	for (int i = 1; i < n; i++){
		if (a[i] < min){
			min = a[i];
			mini = i;
		}
	}
	return mini;
}
System::String^ Array::GetArr(){
	System::String^ Arr;
	for (int i = 0; i < n; i++){
		//if (i == 15) Arr += i.ToString() + System::Environment::NewLine;
		if (i == (n - 1)) Arr = Arr + System::Convert::ToString(a[i]);
		else Arr = Arr + System::Convert::ToString(a[i]) + ",";
	}
	return Arr;
}
std::ostream& operator<<(std::ostream& r, Array& T){
	for (int i = 0; i < T.n; ++i)
	{
		if(i == (T.n - 1)) std::cout << T.a[i];
		else r << T.a[i] << ", ";
	}
	std::cout << std::endl;
	return r;
}
std::istream& operator>>(std::istream& r, Array& T){
	int m;
	std::cout << "Enter the number of array elements: \n";
	std::cin >> m;
	if (T.n != m){
		delete[] T.a;
		T.n = m;
		T.a = new int[m];
	}
	std::cout << "Enter " << m << "elements\n";
	for (int i = 0; i < T.n; ++i)
	{
		r >> T.a[i];
	}
	return r;
}
}
// Exception in method Array::operator-(int key) 
// key is not exist in array