#pragma once
#include <iostream>

class Queue
{
	friend class Iterator;
private:
	int maxSize;
	int head;
	int tail;
	int* mas = nullptr;

public:
	Queue();
	Queue(int);
	~Queue();
	void push(int);
	void pop();
	bool isEmpty() const;
	bool isFull() const;
	int getHead() const;
	void makeEmpty();
	void print();
	int getSize() const;
	int getMaxSize() const;
	int getPointerHead() const;
	int getPointerTail() const;

	Queue& operator=(const Queue& que);

	int* getMas() const;
};

