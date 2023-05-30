#pragma once
#include <iostream>
#include <string>

struct Node {
	int count = 0;
	std::string word;
	Node* left = nullptr;
	Node* right = nullptr;
};

class BinarySearchTree
{
private:
	Node* root;

	void clearElems(Node*);
	void clear(Node*&);
	Node* copyTree(const Node*);

	void printLevel(const Node*, const int);
	void printAl(const Node*);

	bool recInsert(Node*&, std::string);
	//Node* recInsert(Node*, std::string);
	bool recdeleteWord(Node*&, std::string);
	void del2(Node*&, Node*&);
	const Node* recFind(const Node*, std::string);
	int recquantity(const Node*);

public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree&);
	BinarySearchTree(BinarySearchTree&&);

	BinarySearchTree& operator=(const BinarySearchTree&);
	BinarySearchTree& operator=(BinarySearchTree&&);

	void insertWord(std::string);
	void deleteWord(std::string);
	int findWord(std::string);
	int quantityWords();

	void printTree();
	void printAlphabet();
};

