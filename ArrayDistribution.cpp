// Написать функцию, которая получает указатель
// на статический массив и его размер.Функция распределяет положительные, отрицательные и нулевые элементы
// в отдельные динамические массивы.

#include <iostream>
#include <random>
#include <windows.h>
using namespace std;

// Заполнение массив
template<typename T>
void FillArray(T arr[], int size);

// Печать массива
template<typename T>
void PrintArray(T* arr, int size);

// Динамическое выделение памяти для массива
template<typename T>
T* AllocateMemory(T size);

// Очистка памяти
template<typename T>
void ClearMemory(T* arr);

template<typename T>
T* NegativeNumbers(T* arr, int oldSize, int& newSize);

template<typename T>
T* PositiveNumbers(T* arr, int oldSize, int& newSize);

template<typename T>
T* ZeroNumbers(T* arr, int oldSize, int& newSize);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 20;
	int ArraySrc[size];
	FillArray(ArraySrc, size);
	cout << "Заполненный массив " << endl;
	PrintArray(ArraySrc, size);

	int newSize;
	cout << "Массив отрицательных чисел " << endl;
	int* negativeNumb = NegativeNumbers(ArraySrc, size, newSize);
	PrintArray(negativeNumb, newSize);
	ClearMemory(negativeNumb);

	cout << "Массив положительных чисел " << endl;
	int* positiveNumb = PositiveNumbers(ArraySrc, size, newSize);
	PrintArray(positiveNumb, newSize);
	ClearMemory(positiveNumb);

	cout << "Массив нулевых чисел " << endl;
	int* zeroNumb = ZeroNumbers(ArraySrc, size, newSize);
	PrintArray(zeroNumb, newSize);
	ClearMemory(zeroNumb);
	
}


template<typename T>
void FillArray(T arr[], int size) {
	random_device random;
	for (int i = 0; i < size; i++)
		arr[i] = random() % (100 + 50) - 50;
}

template<typename T>
void PrintArray(T* arr, int size) {
	for (int* i = arr; i < arr + size; i++)
		cout << "[ " << *i << "] " << " ";

	cout << endl;
}

template<typename T>
T* AllocateMemory(T size) {
	T* newArray = new int[size];
	return newArray;
}

template<typename T>
void ClearMemory(T* arr) { delete[] arr; };

template<typename T>
T* NegativeNumbers(T* arr, int oldSize, int& newSize) {
	if (arr == nullptr)
		return nullptr;

	newSize = 0;

	for (T* i = arr; i < arr + oldSize; i++) 
		if (*i < 0) ++newSize;
	

	T* newArr = AllocateMemory<T>(newSize);
	if (newArr == nullptr)
		return nullptr;

	T* j = newArr;
	for (T* i = arr; i < arr + oldSize; ++i) {
		if (*i < 0)
			*j++ = *i;
	}

	return newArr;
}

template<typename T>
T* PositiveNumbers(T* arr, int oldSize, int& newSize) {
	if (arr == nullptr)
		return nullptr;

	newSize = 0;

	for (T* i = arr; i < arr + oldSize; i++)
		if (*i < 0) ++newSize;


	T* newArr = AllocateMemory<T>(newSize);
	if (newArr == nullptr)
		return nullptr;

	T* j = newArr;
	for (T* i = arr; i < arr + oldSize; ++i) {
		if (*i > 0)
			*j++ = *i;
	}

	return newArr;
}

template<typename T>
T* ZeroNumbers(T* arr, int oldSize, int& newSize) {
	if (arr == nullptr)
		return nullptr;

	newSize = 0;

	for (T* i = arr; i < arr + oldSize; i++)
		if (*i == 0) ++newSize;


	T* newArr = AllocateMemory<T>(newSize);
	if (newArr == nullptr)
		return nullptr;

	T* j = newArr;
	for (T* i = arr; i < arr + oldSize; ++i) {
		if (*i == 0)
			*j++ = *i;
	}

	return newArr;
}