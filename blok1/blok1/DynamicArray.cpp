#include "DynamicArray.h"

struct IsException { std::string s = "Массивы разной длины\n"; };

struct IsException2 { std::string s = "Доступ к несуществующему элементу\n"; };

DynamicArray::DynamicArray() {
	reserve_size = 0;
	size = default_size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

DynamicArray::DynamicArray(int size) {
	reserve_size = 0;
	this->size = size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

DynamicArray::DynamicArray(int size, int n) {
	reserve_size = 0;
	this->size = size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = n;
	}
}

DynamicArray::DynamicArray(const DynamicArray& mas) {
	std::cout << "Конструктор копирования\n";
	size = mas.size;
	reserve_size = mas.reserve_size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = mas.arr[i];
	}
}

DynamicArray::DynamicArray(DynamicArray&& mas) {
	std::cout << "Конструктор перемещения\n";
	reserve_size = mas.reserve_size;
	size = mas.size;
	arr = mas.arr;
	mas.size = 0;
	mas.reserve_size = 0;
	mas.arr = nullptr;
}

DynamicArray::~DynamicArray() {
	std::cout << "Деструктор\n";
	size = 0;
	reserve_size = 0;
	delete[] arr;
}

int DynamicArray::getSize() {
	return size;
}


int& DynamicArray::operator[](int index) {
	if (index < size) {
		return arr[index];
	}
	else {
		throw IsException2();
	}
}

std::ostream& operator<< (std::ostream& out,  DynamicArray& mas) {
	out << "size = " << mas.getSize() << std::endl;
	for (int i = 0; i < mas.getSize(); i++) {
		out << "mas[" << i << "] = " << mas[i] << std::endl;
	}
	out << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, DynamicArray& mas) {
	in >> mas.size;
	for (int i = 0; i < mas.size; i++) {
		in >> mas[i];
	}
	return in;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& mas) {
	std::cout << "Копирующее присваивание\n";
	size = mas.size;
	reserve_size = mas.reserve_size;
	delete[] arr;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = mas.arr[i];
	}
	return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& mas) {
	std::cout << "Перемещающее присваивание\n";
	if (this != &mas) {
		/*delete[] arr;
		size = mas.size;
		reserve_size = mas.reserve_size;
		arr = mas.arr;

		mas.size = 0;
		mas.reserve_size = 0;
		mas.arr = nullptr;*/

		std::swap(size, mas.size);
		std::swap(reserve_size, mas.reserve_size);
		std::swap(arr, mas.arr);
	}

	return *this;
}


DynamicArray& DynamicArray::resize(int newSize) {
	if (newSize < size) {
		reserve_size += size - newSize;
	}
	else {
		if (reserve_size >= newSize - size) {
			reserve_size -= (newSize - size);
		}
		else {
			int* old = arr;
			arr = new int[newSize+reserve_size];
			for (int i = 0; i < size; i++) {
				arr[i] = old[i];
			}
			for (int i = size; i < newSize; i++) {
				arr[i] = 0;
			}
			delete[] old;
		}
	}
	size = newSize;

	return *this;
}

bool operator==(const DynamicArray& a, const DynamicArray& b) {
	bool boo = true;
	if (a.size != b.size) {
		throw IsException();
	}
	else {
		for (int i = 0; i < a.size; i++) {
			if (a.arr[i] != b.arr[i]) {
				boo = false;
			}
		}
	}
	return boo;
}

bool operator!=(const DynamicArray& a, const DynamicArray& b) {
	int k = 0;
	if (a.size != b.size) {
		throw IsException();
	}
	else {
		for (int i = 0; i < a.size; i++) {
			if (a.arr[i] == b.arr[i]) {
				k++;
			}
		}
	}
	return a.size != k;
}


bool operator>(const DynamicArray& a, const DynamicArray& b) {
	bool res = false;
	int i = 0;
	int max = std::max(a.size,b.size);
	DynamicArray anew = a;
	DynamicArray bnew = b;
	if (a.size != b.size) {
		if (a.size < b.size) {
			anew.resize(max);
			for (int i = a.size; i < max; i++) {
				anew.arr[i] = 0;
			}
		}
		else if (a.size > b.size) {
			bnew.resize(max);
			for (int i = b.size; i < max; i++) {
				bnew.arr[i] = 0;
			}
		}
		while (i < max && anew[i] == bnew[i]) {
			i++;
		}
		if(i!=max) res = anew[i] > bnew[i];
	}
	else {
		while (i < max && anew[i] == bnew[i]) {
			i++;
		}
		if (i != max) res = anew[i] > bnew[i];
	}
	return res;
}

bool operator<(const DynamicArray& a, const DynamicArray& b) {
	bool res = false;
	int i = 0;
	int max = std::max(a.size, b.size);
	DynamicArray anew = a;
	DynamicArray bnew = b;
	if (a.size != b.size) {
		if (a.size < b.size) {
			anew.resize(max);
			for (int i = a.size; i < max; i++) {
				anew.arr[i] = 0;
			}
		}
		else if (a.size > b.size) {
			bnew.resize(max);
			for (int i = b.size; i < max; i++) {
				bnew.arr[i] = 0;
			}
		}
		while (i < max && anew[i] == bnew[i]) {
			i++;
		}
		if (i != max) res = anew[i] < bnew[i];
	}
	else {
		while (i < max && anew[i] == bnew[i]) {
			i++;
		}
		if (i != max) res = anew[i] < bnew[i];
	}
	return res;
}

bool operator>=(const DynamicArray& a, const DynamicArray& b) {
	bool res = false;
	int i = 0;
	int max = std::max(a.size, b.size);
	DynamicArray anew = a;
	DynamicArray bnew = b;
	if (a.size != b.size) {
		if (a.size < b.size) {
			anew.resize(max);
			for (int i = a.size; i < max; i++) {
				anew.arr[i] = 0;
			}
		}
		else if (a.size > b.size) {
			bnew.resize(max);
			for (int i = b.size; i < max; i++) {
				bnew.arr[i] = 0;
			}
		}
		while (i < max && anew[i] == bnew[i]) {
			i++;
		}
		res = anew[i] >= bnew[i];
	}
	else {
		while (i < max && anew[i] == bnew[i]) {
			i++;
		}
		res = anew[i] >= bnew[i];
	}
	return res;
}



bool operator<=(const DynamicArray& a, const DynamicArray& b) {
	bool res = false;
	int i = 0;
	int max = std::max(a.size, b.size);
	DynamicArray anew = a;
	DynamicArray bnew = b;
	if (a.size != b.size) {
		if (a.size < b.size) {
			anew.resize(max);
			for (int i = a.size; i < max; i++) {
				anew.arr[i] = 0;
			}
		}
		else if (a.size > b.size) {
			bnew.resize(max);
			for (int i = b.size; i < max; i++) {
				bnew.arr[i] = 0;
			}
		}
		while (i < max && anew[i] == bnew[i]) {
			i++;
		}
		res = anew[i] <= bnew[i];
	}
	else {
		while (i < max && anew[i] == bnew[i]) {
			i++;
		}
		res = anew[i] <= bnew[i];
	}
	return res;
}



DynamicArray operator+(const DynamicArray& a, const DynamicArray& b) {
	int s = a.size + b.size;
	DynamicArray mas(s);
	for (int i = 0; i < a.size; i++) {
		mas[i] = a.arr[i];
	}
	for (int i = 0; i < b.size; i++) {
		mas[i + a.size] = b.arr[i];
	}
	return mas;
}


DynamicArray& DynamicArray::reserve(int n) {
	int* old = arr;
	arr = new int[size + n];
	for (int i = 0; i < size; i++) {
		arr[i] = old[i];
	}
	delete[] old;
	reserve_size = n;
	return *this;
}

int DynamicArray::capacity() {
	return reserve_size;
}

DynamicArray& DynamicArray::pushBack(int x) {
	resize(size + 1);
	arr[size-1] = x;
	return *this;
}

int DynamicArray::popBack() {
	int res = 0;
	if (size == 0) {
		throw IsException();
	}
	else {
		res = arr[size - 1];
		resize(size - 1);
	}
	return res;
}