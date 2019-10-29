//#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
namespace ARRAY{
//template <typename T>
class Array{
private:
	int *a;
	int n;
public:
	Array(); // конструктор по умолчанию
	Array(int m);
	Array(int *x, int m = 1);
	~Array();
	Array(const Array& T); // конструктор копирования
	Array& operator=(const Array&); // операция присвоения
	int& operator[](int); // считывание эллементов
	int Find(int key); // по позиции
	Array& operator+=(int key); // Добавление key в конец массива
	Array operator+(int key); // создание массива b = *this + key
	Array& operator+=(const Array&);
	Array operator+(const Array& T);
	Array& operator-=(int key); // удаление эллемента с позиции pos
	Array operator-(int key); // удаление эллемента по ключу
	bool operator==(const Array&); // проверка равентсва массива
	bool operator!=(const Array&);
	int Max(); // находит max в массиве, возвращает индекс
	int Min();
	void Sorting();
	friend std::ostream& operator<<(std::ostream& r, Array&);
	friend std::istream& operator>>(std::istream& r, Array&);
};
}
#endif 