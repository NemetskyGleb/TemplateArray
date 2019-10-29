//#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
namespace ARRAY{
template <typename T>
class Array{
private:
	T *a;
	int n;
public:
	Array(); // конструктор по умолчанию
	Array(int m);
	Array(T *x, int m = 1);
	~Array();
	Array(const Array&); // конструктор копирования
	Array& operator=(const Array&); // операция присвоения
	T& operator[](T pos); // считывание эллементов
	T Find(T key); // по позиции
	Array& operator+=(T key); // Добавление key в конец массива
	Array operator+(T key); // создание массива b = *this + key
	Array& operator+=(const Array&);
	Array operator+(const Array&);
	Array& operator-=(T key); // удаление эллемента с позиции pos
	Array operator-(T key); // удаление эллемента по ключу
	bool operator==(const Array&); // проверка равентсва массива
	bool operator!=(const Array&);
	T Max(); // находит max в массиве, возвращает индекс
	T Min();
	void Sorting();
	template <typename U>
	friend std::ostream& operator<<(std::ostream& r, Array<U>&);
	template <typename U>
	friend std::istream& operator>>(std::istream& r, Array<U>&);
};
}
#endif 