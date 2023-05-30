#include "Queue.h"

Queue::Queue() {
	maxSize = 0;
	mas = new int[maxSize];
	makeEmpty();
}

Queue::Queue(int maximal) {
	maxSize = maximal;
	mas = new int[maxSize];
	makeEmpty();
}

/*
Queue& Queue::operator=(const Queue& que) {
	std::cout << "Копирующее присваивание\n";
	head = que.head;
	tail = que.tail;
	maxSize = que.maxSize;
	delete[] mas;
	mas = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		mas[i] = que.mas[i];
	}
	return *this;
}*/


void Queue::makeEmpty() {
	head = -1;
	tail = -1;
}

Queue::~Queue() {
	delete[] mas;
	maxSize = 0;
}

bool Queue::isEmpty() const{
	return head == -1;
}

bool Queue::isFull() const{
	return head == tail + 1 || head == 0 && tail == maxSize - 1;
}

void Queue::push(int element) {
	if (isFull()) {
		std::cout << "будет переполнение" << std::endl;
	}
	else {
		if (head == -1) head = 0;
		tail = (tail + 1) % maxSize;
		mas[tail] = element;
	}
}

void Queue::pop() {
	if (isEmpty()) {
		std::cout << "попытка извлечь из пустого" << std::endl;
	}
	else {
		if (head == tail) makeEmpty();
		else head = (head + 1) % maxSize;
	}
}

void Queue::print() {
	int i = head;
	while (i != tail) {
		std::cout << mas[i] << std::endl;
		i = (i + 1) % maxSize;
	}
	std::cout << mas[i] << std::endl << std::endl;
}

int Queue::getHead() const{
	if (isEmpty()) {
		std::cout << "попытка взять из пустого\n";
		exit(0);
	}
	return mas[head];
}

int Queue::getSize() const{
	if (isEmpty()) return 0;
	return abs((tail - head) % maxSize) + 1;
}

int Queue::getPointerHead() const{
	return head;
}

int Queue::getPointerTail() const {
	return tail;
}

int Queue::getMaxSize() const{
	return maxSize;
}

int* Queue::getMas() const {
	int* newarr = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		newarr[i] = mas[i];
	}
	return newarr;
}