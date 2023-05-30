#include "Iterator.h"

Iterator::Iterator(const Queue& q): que(q) {
	pointer = que.getPointerHead();
}

Iterator::~Iterator() {
	pointer = 0;
}

void Iterator::start() {
	if (que.isEmpty()) {
		std::cout << "очередь пуста" << std::endl;
	}
	pointer = que.getPointerHead();
}

void Iterator::next() {
	if (!que.isEmpty()) {//если очередь не пуста, могу двигаться
		pointer=(pointer+1)%que.maxSize;
	}
}

int Iterator::getValue() const{
	if (que.isEmpty()) {//если очередь пуста
		exit(0);
	}
	return que.mas[pointer];
}

bool Iterator::finish() const{
	if (que.isEmpty()) {//если очередь пуста
		exit(0);
	}
	return pointer==que.getPointerTail();
}