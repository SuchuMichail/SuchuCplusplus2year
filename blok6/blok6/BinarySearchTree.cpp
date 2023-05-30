#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BinarySearchTree::BinarySearchTree(BinarySearchTree&& tree) {
	//std::cout << "Конструктор перемещения\n";
	root = tree.root;
	tree.root = nullptr;
}

BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree&& tree) {
	//std::cout << "Перемещающее присваивание\n";
	if (this != &tree) {
		std::swap(root, tree.root);
	}
	return *this;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree) {
	//std::cout << "Конструктор копирования\n";
	root = copyTree(tree.root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& tree) {
	//std::cout << "Копирующее присваивание\n";
	clear(root);
	root = copyTree(tree.root);
	return *this;
}

Node* BinarySearchTree::copyTree(const Node* root) {
	if (!root) {
		return nullptr;
	}
	Node* rootCopy = new Node;
	rootCopy->count = root->count;
	rootCopy->word = root->word;
	try {
		rootCopy->left = copyTree(root->left);
		rootCopy->right = copyTree(root->right);
	}
	catch (std::bad_alloc) {
		clear(rootCopy);
		throw;
	}
	return rootCopy;
}

BinarySearchTree::~BinarySearchTree() {
	//std::cout << "Деструктор\n";
	clear(root);
}

void BinarySearchTree::clearElems(Node* root) {
	if (!root) {
		return;
	}
	clearElems(root->left);
	clearElems(root->right);
	delete root;
}

void BinarySearchTree::clear(Node*& root) {
	clearElems(root);
	root = nullptr;
}

void BinarySearchTree::printTree() {
	printLevel(root, 0);
	std::cout << std::endl;
}

void BinarySearchTree::printLevel(const Node* root, const int level) {
	for (int i = 0; i < level; i++) {
		std::cout << " ";
	}
	std::cout << root->word << root->count << std::endl;
	if (root->left) {
		printLevel(root->left, level + 1);
	}
	if (root->right) {
		printLevel(root->right, level + 1);
	}
}
/*
Node* BinarySearchTree::recInsert(Node* root, std::string x) {
	if (!root) {
		Node* newnode = new Node;
		newnode->count = 1;
		newnode->word = x;
		return newnode;
	}

	if (x < root->word) {
		root->left = recInsert(root->left, x);
	}
	if (x > root->word) {
		root->right = recInsert(root->right, x);
	}
	if (x == root->word) {
		root->count++;
	}
	return root;
}*/

bool BinarySearchTree::recInsert(Node*& root, std::string x) {
	if (root == nullptr) {
		Node* newnode = new Node;
		newnode->count = 1;
		newnode->word = x;
		root = newnode;
		return true;
	}
	if (x < root->word) {
		return recInsert(root->left, x);
	}
	if (x > root->word) {
		return recInsert(root->right, x);
	}
	if (x == root->word) {
		root->count++;
	}
	return false;
}

void BinarySearchTree::insertWord(std::string x) {
	//root = recInsert(root, x);
	bool res = recInsert(root, x);
}

// Удаление элемента x из дерева двоичного поиска root.
// Результат true, если элемент найден и удален.
// Результат false, если x в дереве не найден.
bool BinarySearchTree::recdeleteWord(Node*& root, std::string x){
	if (root)std::cout << root->word << std::endl;
	if(!root){
		return false;
	}
	if(x < root->word){
		return recdeleteWord(root->left,x);
	}
	if(x > root->word){
		return recdeleteWord(root->right,x);
	}

	if (root->count > 1) {
		//std::cout << "root = " << root->word << std::endl;
		root->count--;
	}
	else {
		Node* nodeToDel = root;
		if (!root->left) {//нет потомка слева, подтянем потомка справа или nullptr, если его нет
			root = root->right;
		}
		else if (!root->right) {
			//std::cout << "root before = " << root->word << std::endl;
			root = root->left;
			//std::cout << "root after = " << root->word << std::endl;
		}
		else {//два потомка
			//std::cout << "Я тут был\n";
			del2(root->left, nodeToDel);
		}
		delete nodeToDel;
		nodeToDel = nullptr;
	}
	
	return true;
}

void BinarySearchTree::del2(Node*& leftSubTree, Node*& root) {
	if (leftSubTree->right) {//пока есть потомок справа спускаемся
		del2(leftSubTree->right, root);
	}
	else {//это наибольший элемент левого поддерева
		root->word = leftSubTree->word;
		root->count = leftSubTree->count;
		root = leftSubTree;
		leftSubTree = leftSubTree->left;
	}
}

void BinarySearchTree::deleteWord(std::string x) {
	bool res = recdeleteWord(root, x);
}

int BinarySearchTree::recquantity(const Node* root) {
	if (root == nullptr) {
		return 0;
	}	
	return root->count + recquantity(root->left) + recquantity(root->right);
}

int BinarySearchTree::quantityWords() {
	int res = recquantity(root);
	return res;
}

const Node* BinarySearchTree::recFind(const Node* root, std::string x) {
	if (root == nullptr) {
		return nullptr;
	}
	if (x < root->word) {
		return recFind(root->left, x);
	}
	if (x > root->word) {
		return recFind(root->right, x);
	}
	return root;
}

int BinarySearchTree::findWord(std::string x) {
	const Node* res = recFind(root, x);
	if (res == nullptr) {
		return 0;
	}
	return res->count;
}

void BinarySearchTree::printAlphabet() {
	printAl(root);
	std::cout << std::endl;
}
void BinarySearchTree::printAl(const Node* root) {
	if (!root) {
		return;
	}
	printAl(root->left);
	std::cout << root->word << root->count << " ";
	printAl(root->right);
}