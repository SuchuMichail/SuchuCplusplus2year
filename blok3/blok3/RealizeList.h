#pragma once
#include "List.h"
#include <iostream>

template<typename T>
class RealizeList: public List<T>
{
private:
	template<typename N>
	struct Node {
		Node<N>* next;
		Node<N>* prev;
		T data;
	};

	Node<T>* head;
	Node<T>* buf;

public:
	//класс-наследник абстрактного итератора
	template<typename L>
	class RealizeIterator : public Iterator<L> {
	private:
		const RealizeList<T>& list;
		Node<T>* pointer;

	public:
		RealizeIterator(const RealizeList<T>& l) : list(l), pointer(l.getPointerHead()) {
		}

		~RealizeIterator() {
			pointer = nullptr;
		}
		void start() {
			std::cout << "Start\n";
			if (list.isEmpty()) {
				std::cout << "List is empty\n";
			}
			else {
				pointer = list.getPointerHead();
			}
		}

		T getCurrentData() const {
			return pointer->data;
		}

		Node<T>* getCurrentPointer() {
			return pointer;
		}

		void moveNext() {
			if (!isAll()) {
				pointer = pointer->next;
			}
			else {
				std::cout << "Двигаться некуда\n";
			}
		}

		bool isAll() const {
			return pointer == list.getPointerBuf();
		}
	};

	RealizeList() {
		buf = new Node<T>;
		head = buf;
		buf->next = head;
		buf->prev = head;
		head->next = buf;
		head->prev = buf;
	}

	RealizeList(const RealizeList<T>& list) {
		std::cout << "Конструктор копирования\n";
		buf = new Node<T>;
		head = buf;
		buf->next = head;
		buf->prev = head;
		head->next = buf;
		head->prev = buf;

		Iterator<T>* iter = new RealizeIterator<T>(list);
		iter->start();
		Node<T>* tmp = head;
		while (!iter->isAll()) {
			Node<T>* newnode = new Node<T>;
			newnode->data = iter->getCurrentData();
			newnode->next = buf;
			newnode->prev = tmp;
			if (head == buf) {
				head = newnode;
			}
			tmp->next = newnode;
			tmp = newnode;
			iter->moveNext();
		}

		delete iter;
	}
	RealizeList(RealizeList<T>&& list) {
		std::cout << "Конструктор перемещения\n";
		head = list.head;
		buf = list.buf;
		list.head = nullptr;
		list.buf = nullptr;
	}
	RealizeList& operator=(const RealizeList<T>& list) {
		std::cout << "Копирующее присваивание\n";
		//system("pause");

		makeEmpty();

		buf = new Node<T>;
		head = buf;
		buf->next = head;
		buf->prev = head;
		head->next = buf;
		head->prev = buf;

		Iterator<T>* iter = new RealizeIterator<T>(list);
		iter->start();
		Node<T>* tmp = head;
		while (!iter->isAll()) {
			//system("pause");
			Node<T>* newnode = new Node<T>;
			newnode->data = iter->getCurrentData();
			newnode->next = buf;
			newnode->prev = tmp;
			if (head == buf) {
				head = newnode;
			}
			tmp->next = newnode;
			tmp = newnode;
			iter->moveNext();
		}

		delete iter;

		return *this;
	}
	RealizeList& operator=(RealizeList<T>&& list) {
		std::cout << "Перемещающее присваивание\n";
		if (this != &list) {
			std::swap(head, list.head);
			std::swap(buf, list.buf);
		}
		return *this;
	}

	~RealizeList() {
		makeEmpty();
		delete buf;
		head = buf = nullptr;
	}

	void insertElement(T elem, Iterator<T>& iter) {
		RealizeIterator<T>* realiter = dynamic_cast<RealizeIterator<T>*>(&iter);
		Node<T>* tmp = realiter->getCurrentPointer();
		
		Node<T>* newnode = new Node<T>;
		newnode->data = elem;		
		newnode->next = tmp;
		newnode->prev = tmp->prev;
		tmp->prev->next = newnode;
		tmp->prev = newnode;

		 //std::cout << "realiter " << realiter->getCurrentData() << "\n";
		if (head == buf) {
			head = newnode;
			buf->next = newnode;
		}
		
			/*std::cout << "tmp = " << tmp << "\n";
			std::cout << "tmp prev = " << tmp->prev << "\n";
			std::cout << "tmp next = " << tmp->next << "\n";
			std::cout << "node = " << newnode << "\n";
			std::cout << "node prev = " << newnode->prev << "\n";
			std::cout << "node next = " << newnode->next << "\n";
			std::cout << "head = " << head->data << "\n"; iter.moveNext();*/
	}

	void deleteElement(Iterator<T>& iter) {
		//std::cout << "  data = " << iter.getCurrentData() << "\n";
		if (!isEmpty()) {
			//std::cout << "  data = " << iter.getCurrentData() << "\n";
			RealizeIterator<T>* realiter = dynamic_cast<RealizeIterator<T>*>(&iter);
			Node<T>* tmp = realiter->getCurrentPointer();
			//std::cout << "Yare yare data = " << realiter->getCurrentData() << "\n";
			//std::cout << "Yare  data = " << tmp->data << "\n";
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next; 
			iter.moveNext();
			delete tmp;
		}
	}

	Iterator<T>& findFirstOccurrence(T elem) {
		Iterator<T>* iter = new RealizeIterator<T>(*this);
		iter->start();
		while (iter->getCurrentData() != elem) {
			if (iter->isAll()) {
				std::cout << "Вхождение не найдено\n";
				exit(0);
			}
			//std::cout << "Current data = " << iter->getCurrentData() << "\n";
			iter->moveNext();
		}
		//std::cout << "end data = " << iter->getCurrentData() << "\n";
		return *iter;
	}

	void makeEmpty() {
		while (head != buf) {
			Node<T>* tmp = head;
			buf->next = head->next;
			head = head->next;
			delete tmp;
		}
	}

	bool isEmpty() const {
		return head == buf;
	}

	int quantityElements() {
		int count = 0;
		Iterator<T>* iter = new RealizeIterator<T>(*this);
		while (!iter->isAll()) {
			count++;
			iter->moveNext();
		}
		return count;
	}

	Iterator<T>& getIterOnFirstElem() {
		RealizeIterator<T>* iter = new RealizeIterator<T>(*this);
		return *iter;
	}

	Node<T>* getPointerHead() const {
		return head;
	}

	Node<T>* getPointerBuf() const {
		return buf;
	}

	void Print() {
		Node<T>* iterator = head;
		while (iterator != buf) {
			std::cout << iterator->data << std::endl;
			iterator = iterator->next;
		}
		std::cout << std::endl;
	}

};

