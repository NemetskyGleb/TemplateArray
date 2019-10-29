#pragma once
#include <iostream>

template <typename T>
class Array{
private:
	T *a;
	int n;
public:
	Array(); // конструктор по умолчанию
	Array(int m); // конструктор с параметром m - длина массива
	Array(T *x, int m = 1); // конструктор с параметрами: массив, длина массива(по умолчанию 1)
	~Array(); // деструктор
	Array(const Array&); // конструктор копирования
	Array& operator=(const Array&); // операция присвоения
	T& operator[](int pos); // считывание эллементов
	T Find(T key); // по позиции
	Array& operator+=(T key); // Добавление key в конец массива
	Array operator+(T key); // создание массива b = *this + key
	Array& operator+=(const Array&);
	Array operator+(const Array&);
	Array& operator-=(T key); // удаление эллемента с позиции pos
	Array operator-(T key); // удаление эллемента по ключу
	bool operator==(const Array&); // проверка равентсва массива
	bool operator!=(const Array&);
	int Max(); // находит max в массиве, возвращает индекс
	int Min(); 
	void Sorting(); // сортировка "Шейкером"
	template <typename U> friend std::ostream& operator<<(std::ostream& r, Array<U>&); // вывод
	template <typename U> friend std::istream& operator>>(std::istream& r, Array<U>&); // ввод
};
/****Realisation below****/
template <typename T> Array<T>::Array(){
	a = new T[1];
	n = 1;
}
template <typename T> Array<T>::Array(int m){
	a = new T[m];
	n = m;
}
template <typename T> Array<T>::Array(T* x, int m){
	n = m;
	a = new T[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = x[i];
	}
}
template <typename T> Array<T>::Array(const Array& A){
	n = A.n;
	a = new T[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = A.a[i];
	}
}
template <typename T> Array<T>& Array<T>::operator=(const Array& A){
	if (this != &A){
		if (n != A.n){
			delete[] a;
			n = A.n;
			a = new T[n];
		}
		for (int i = 0; i < n; ++i)
		{
			a[i] = A.a[i];
		}
	}
	return *this;
}
template <typename T> Array<T>::~Array(){
	delete[] a;
}
template <typename T> T& Array<T>::operator[](int pos){
	if (pos < 0 || pos > n){
		std::cout << "Incorrect position. Return a[0]\n";
		return a[0];
	}
	return a[pos];
}
template <typename T> Array<T> Array<T>::operator+(const Array& A){
	int m = n + A.n;
	Array temp(m);
	for (int i = 0; i < n; i++){
		temp.a[i] = a[i];
	}
	for (int i = n, k = 0; i < m; i++, k++){
		temp.a[i] = A.a[k];
	}
	return temp;
}
template <typename T> Array<T>& Array<T>::operator+=(const Array& A){
	return *this = *this + A;
}
template <typename T> Array<T>& Array<T>::operator+=(T key){
	T *t = new T[n + 1];
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
template <typename T> Array<T> Array<T>::operator+(T key){
	Array Res(n + 1);
	for (int i = 0; i < n; ++i)
	{
		Res.a[i] = a[i];
	}
	Res.a[n] = key;
	return Res;
}
template <typename T> Array<T> Array<T>::operator-(T key){
	Array Res(n - 1);
	T k = Find(key);
	if (k >= 0){
		for (int i = 0; i < k; i++){
			Res.a[i] = a[i];
		}
		for (int i = k; i < n; i++){
			Res.a[i] = a[i + 1];
		}
		return Res;
	}
	else {
		std::cout << "There is not your element in array!" << std::endl;
		return *this;
	}
}
template <typename T> Array<T>& Array<T>::operator-=(T key){
	return *this = *this - key;
}
template <typename T> bool Array<T>::operator==(const Array& A){
	for (int i = 0; i < n; i++)
	if (a[i] != A.a[i])
		return false;
	return true;
}
template <typename T> bool Array<T>::operator!=(const Array& A){
	for (int i = 0; i < n; i++)
	if (a[i] == A.a[i])
		return true;
	return false;
}
template <typename T> void Array<T>::Sorting(){
	int left = 0, right = n - 1;
	bool flag = true;
	while (flag && (left < right)) {
		flag = false;
		for (int i = left; i < right; ++i) {
			if (a[i] > a[i + 1]) {
				T temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				flag = true;
			}
		}
		right--;
		for (int i = right; i > left; --i) {
			if (a[i] < a[i - 1]) {
				T temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
				flag = true;
			}
		}
		left++;
	}
}
template <typename T> T Array<T>::Find(T key){
	for (int i = 0; i < n; i++){
		if (a[i] == key)
			return i;
	}
	return -1;
}
template <typename T> int Array<T>::Max(){
	T maxi = 0;
	T max = a[0];
	for (int i = 1; i < n; i++){
		if (a[i] > max){
			max = a[i];
			maxi = i;
		}
	}
	return maxi;
}
template <typename T> int Array<T>::Min(){
	T mini = 0;
	T min = a[0];
	for (int i = 1; i < n; i++){
		if (a[i] < min){
			min = a[i];
			mini = i;
		}
	}
	return mini;
}
template <typename T> std::ostream& operator<<(std::ostream& r, Array<T>& A){
	for (int i = 0; i < A.n; ++i)
	{
		if (i == (A.n - 1)) std::cout << A.a[i];
		else r << A.a[i] << ", ";
	}
	std::cout << std::endl;
	return r;
}
template <typename T> std::istream& operator>>(std::istream& r, Array<T>& A){
	int m;
	std::cout << "Enter the number of array elements: \n";
	std::cin >> m;
	if (A.n != m){
		delete[] A.a;
		A.n = m;
		A.a = new T[m];
	}
	for (int i = 0; i < A.n; ++i)
	{
		std::cout << "Enter " << i + 1 << " elements: \n";
		r >> A.a[i];
	}
	std::cin.get();
	return r;
}
/* TODO:
	Add Support of Type Conversion(double = int and etc)
*/
// Exception in method Array::operator-(int key) 
// key is not exist in array