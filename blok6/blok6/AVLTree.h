#pragma once
#include <iostream>
#include <string>

struct AVLNode {
	int count = 0;
	std::string word;
	int balance = 0;
	AVLNode* left = nullptr;
	AVLNode* right = nullptr;
};

class AVLTree
{
private:
	AVLNode* root;

	void clearElems(AVLNode*);
	void clear(AVLNode*&);

	const AVLNode* recFind(const AVLNode*, std::string);

	void del2(AVLNode*&, AVLNode*&);

	bool balanceInsertToLeft(AVLNode*&);
	bool balanceInsertToRight(AVLNode*&);
	bool balanceDeleteToLeft(AVLNode*&);
	bool balanceDeleteToRight(AVLNode*&);

	bool RRotation(AVLNode*&,bool);
	bool LRRotation(AVLNode*&,bool);

	bool LRotation(AVLNode*&,bool);
	bool RLRotation(AVLNode*&,bool);

	bool insertElem(AVLNode*&, std::string);
	bool deleteElem(AVLNode*&, std::string);

	void printLevel(const AVLNode*, const int);

public:
	AVLTree();
	~AVLTree();

	int findWord(std::string);
	void printTree();

	void insert(std::string);
	void deleteE(std::string);

};

