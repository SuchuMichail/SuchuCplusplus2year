#pragma once
#include "Iterator.h"

template<typename T>
class List
{
public:
	virtual void insertElement(T,Iterator<T>&) = 0;
	virtual void deleteElement(Iterator<T>&) = 0;
	virtual Iterator<T>& findFirstOccurrence(T) = 0;
	virtual void makeEmpty() = 0;
	virtual bool isEmpty() const = 0;
	virtual int quantityElements() = 0;
	virtual Iterator<T>& getIterOnFirstElem() = 0;

	virtual void Print() = 0;

	virtual ~List() {};
};

