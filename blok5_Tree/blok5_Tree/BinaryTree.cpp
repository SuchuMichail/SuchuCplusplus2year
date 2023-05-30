#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::BinaryTree(BinaryTree&& tree) {
	//std::cout << "Конструктор перемещения\n";
	root = tree.root;
	tree.root = nullptr;
}

BinaryTree& BinaryTree::operator=(BinaryTree&& tree) {
	//std::cout << "Перемещающее присваивание\n";
	if (this != &tree) {
		std::swap(root, tree.root);
	}
	return *this;
}

BinaryTree::BinaryTree(const BinaryTree& tree) {
	//std::cout << "Конструктор копирования\n";
	root = copyTree(tree.root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& tree) {
	//std::cout << "Копирующее присваивание\n";
	clear(root);
	root = copyTree(tree.root);
	return *this;
}

Node* BinaryTree::copyTree(const Node* root) {
	if (!root) {
		return nullptr;
	}
	Node* rootCopy = new Node;
	rootCopy->info = root->info;
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

BinaryTree::~BinaryTree() {
	//std::cout << "Деструктор\n";
	clear(root);
}

void BinaryTree::clearElems(Node* root) {
	if (!root) {
		return;
	}
	clearElems(root->left);
	clearElems(root->right);
	delete root;
}

void BinaryTree::clear(Node*& root) {
	clearElems(root);
	root = nullptr;
}

void BinaryTree::insertElement(int x, std::vector<int> arr) {
	Node* tmp = root;
	Node* support = tmp;
	int i = 0;
	while (tmp != nullptr && i!=arr.size()) {
		support = tmp;
		if (arr[i] == 0) {
			tmp = tmp->left;
		}
		if (arr[i] == 1) {
			tmp = tmp->right;
		}
		i++;
	}
	if (i == arr.size() && tmp != nullptr) {//вершина дерева
		tmp->info = x;
	}
	if (i == arr.size() && tmp == nullptr) {//предыдущий был листом, создаём новый лист
		Node* newnode = new Node;
		newnode->info = x;
		newnode->left = nullptr;
		newnode->right = nullptr;
		if (arr.size() == 0) {
			root = newnode;
		}
		else {
			if (arr[arr.size() - 1] == 0) {
				support->left = newnode;
			}
			if (arr[arr.size() - 1] == 1) {
				support->right = newnode;
			}
		}
	}
	if (i != arr.size() && tmp == nullptr) {//предыдущий был листом, но последовательность не закончилась
		std::cout << "Нельзя вставить новый элемент\n";
	}
}

void BinaryTree::printTreeLR() {
	printLeftRight(root);
	std::cout << std::endl;
}

void BinaryTree::printLeftRight(const Node* root) {
	if (!root) {
		return;
	}
	printLeftRight(root->left);
	std::cout << root->info << " ";
	printLeftRight(root->right);
}

void BinaryTree::printTreeLevel() {
	printLevel(root, 0);
	std::cout << std::endl;
}

void BinaryTree::printLevel(const Node* root, const int level) {
	for (int i = 0; i < level; i++) {
		std::cout << " ";
	}
	std::cout << root->info << std::endl;
	if (root->left) {
		printLevel(root->left, level + 1);
	}
	if (root->right) {
		printLevel(root->right, level + 1);
	}
}

void BinaryTree::recEvenNumbers(const Node* root, int& quantity) {
	if (!root) {
		return;
	}
	recEvenNumbers(root->left, quantity);
	recEvenNumbers(root->right, quantity);
	if (root->info % 2 == 0) {
		quantity++;
	}
}

int BinaryTree::quantityEvenNumbers() {
	int quantity = 0;
	recEvenNumbers(root, quantity);
	return quantity;
}

bool BinaryTree::onlyPositive() {
	bool boo = true;
	recPositive(root, boo);
	return boo;
}

void BinaryTree::recPositive(const Node* root, bool& boo) {
	if (!root) {
		return;
	}
	recPositive(root->left, boo);
	recPositive(root->right, boo);
	if (root->info <= 0) {
		boo = false;
	}
}

void BinaryTree::deleteAllLeafs() {
	recLeafs(root);
}

void BinaryTree::recLeafs(Node*& root) {
	if (root == nullptr) {
		return;
	}
	if (root->left == nullptr && root->right == nullptr) {
		delete root;
		root = nullptr;
	}
	else {
		recLeafs(root->left);
		recLeafs(root->right);
	}
}

double BinaryTree::arithmeticMean() {
	int count = 0;
	double sum = 0;
	recArithmetic(root, sum, count);
	return sum/count;
}

void BinaryTree::recArithmetic(const Node* root, double& sum, int& count) {
	if (root == nullptr) {
		return;
	}
	recArithmetic(root->left, sum, count);
	recArithmetic(root->right, sum, count);
	count++;
	sum += root->info;
}

std::vector<int> BinaryTree::findElement(int x) {
	std::vector<int> res;
	bool flag = false;
	recFind(root, res, x, flag);
	return res;
}

void BinaryTree::recFind(const Node* root, std::vector<int>& res, const int& x, bool& flag) {
	if (root == nullptr){
		return;
	}
	if (root->info == x) {
		flag = true;
	}

	if (root->left != nullptr && flag == false) {
		res.push_back(0);
		recFind(root->left, res, x, flag);
	}
	if (root->right != nullptr && flag == false) {
		res.push_back(1);
		recFind(root->right, res, x, flag);
	}

	if(flag == false && res.size() > 0) {
		res.pop_back();
	}
	/*std::cout << " r=" << root->info << " flag = " << flag << std::endl << "f: ";
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i] << " ";
	}
	std::cout << std::endl << std::endl;*/
}


bool BinaryTree::isBinarySearch() {
	bool res = true;
	recSearch(root, res);
	return res;
}

void BinaryTree::recSearch(const Node* root, bool& res) {
	//std::cout << "root = " << root->info << std::endl;
	if (root == nullptr) {
		res = true;
		return;
	}

	if (root->left != nullptr && root->right != nullptr) {
		if (!(root->left->info < root->info && root->right->info > root->info)) {
			res = false;
			//std::cout << "broken root " << root->info << std::endl;
		}
	}
	else if (root->left != nullptr) {
		if (!(root->left->info < root->info)) {
			res = false; //std::cout << "broken root " << root->info << std::endl;
		}
	}
	else if (root->right != nullptr) {
		if (!(root->right->info > root->info)) {
			res = false; //std::cout << "broken root " << root->info << std::endl;
		}
	}
	
	if (root->left != nullptr) { 
		recSearch(root->left, res); 
	}
	if (root->right != nullptr) {
		recSearch(root->right, res);
	}
}