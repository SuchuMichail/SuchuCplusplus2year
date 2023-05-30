#pragma once
#include <iostream>

class DynamicArray
{
	friend std::ostream& operator<< (std::ostream&, DynamicArray&);
	friend std::istream& operator>> (std::istream&, DynamicArray&);
	friend bool operator==(const DynamicArray&, const DynamicArray&);
	friend bool operator!=(const DynamicArray&, const DynamicArray&);
	friend bool operator>(const DynamicArray&, const DynamicArray&);
	friend bool operator<(const DynamicArray&, const DynamicArray&);
	friend bool operator>=(const DynamicArray&, const DynamicArray&);
	friend bool operator<=(const DynamicArray&, const DynamicArray&);
	friend DynamicArray operator+(const DynamicArray&, const DynamicArray&);

private:
	const int default_size = 2;
	int* arr = nullptr;
	int size;
	int reserve_size;

public:
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(int size, int n);
	DynamicArray(const DynamicArray&);
	DynamicArray(DynamicArray&&);



	~DynamicArray();

	int getSize();
	DynamicArray& resize(int);

	DynamicArray& operator=(const DynamicArray&);
	DynamicArray& operator=(DynamicArray&&);

	int& operator[](int index);
	DynamicArray& reserve(int);
	DynamicArray& pushBack(int);
	int popBack();

	int capacity();
};

