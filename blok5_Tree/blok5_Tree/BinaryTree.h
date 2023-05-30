#pragma once
#include <iostream>
#include <vector>

struct Node {
	int info;
	Node* left = nullptr;
	Node* right = nullptr;
};

class BinaryTree
{
private:
	Node* root;

	void clearElems(Node*);
	void clear(Node*&);
	Node* copyTree(const Node*);

	void printLeftRight(const Node*);
	void printLevel(const Node*, const int);

	void recEvenNumbers(const Node*, int&);
	void recPositive(const Node*, bool&);
	void recLeafs(Node*&);
	void recArithmetic(const Node*, double&, int&);
	void recFind(const Node*, std::vector<int>&, const int&, bool&);
	void recSearch(const Node*, bool&);

public:

	BinaryTree();
	~BinaryTree();
	BinaryTree(const BinaryTree&);
	BinaryTree(BinaryTree&&);
	

	BinaryTree& operator=(const BinaryTree&);
	BinaryTree& operator=(BinaryTree&&);

	void insertElement(int, std::vector<int>);
	void printTreeLR();
	void printTreeLevel();
	

	int quantityEvenNumbers();
	bool onlyPositive();
	void deleteAllLeafs();
	double arithmeticMean();
	std::vector<int> findElement(int);

	bool isBinarySearch();
};

