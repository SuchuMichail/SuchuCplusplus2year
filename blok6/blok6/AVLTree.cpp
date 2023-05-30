#include "AVLTree.h"

AVLTree::~AVLTree() {
	//std::cout << "Деструктор\n";
	clear(root);
}

void AVLTree::clearElems(AVLNode* root) {
	if (!root) {
		return;
	}
	clearElems(root->left);
	clearElems(root->right);
	delete root;
}

void AVLTree::clear(AVLNode*& root) {
	clearElems(root);
	root = nullptr;
}

const AVLNode* AVLTree::recFind(const AVLNode* root, std::string x) {
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

int AVLTree::findWord(std::string x) {
	const AVLNode* res = recFind(root, x);
	if (res == nullptr) {
		return 0;
	}
	return res->count;
}

void AVLTree::printTree() {
	printLevel(root, 0);
	std::cout << std::endl;
}

void AVLTree::printLevel(const AVLNode* root, const int level) {
	for (int i = 0; i < level; i++) {
		std::cout << "  ";
	}
	std::cout << root->balance << root->word << root->count << std::endl;
	if (root->left) {
		printLevel(root->left, level + 1);
	}
	if (root->right) {
		printLevel(root->right, level + 1);
	}
}

AVLTree::AVLTree() {
	root = nullptr;
}

void AVLTree::insert(std::string x) {
	bool res = insertElem(root, x);
}

bool AVLTree::insertElem(AVLNode*& root, std::string x) {
	if (!root) {
		AVLNode* newnode = new AVLNode;
		newnode->word = x;
		newnode->left = nullptr;
		newnode->right = nullptr;
		newnode->balance = 0;
		newnode->count = 1;
		root = newnode;
		return true;
	}
	if (x < root->word) {
		if (insertElem(root->left, x)) {
			// если после вставки высота левого поддерева увеличилась,
			// проверим и восстановим баланс
			return balanceInsertToLeft(root);
		}
		return false;// если после вставки высота поддерева не выросла, то баланс не нарушен
	}
	if (x > root->word) {
		if (insertElem(root->right, x)) {
			return balanceInsertToRight(root);
		}
		return false;
	}
	if (x == root->word) {
		root->count++;
	}
	return false;
}

// Балансировка дерева при вставке элемента слева от корня.
// Поддеревья слева и справа от корня уже сбалансированы.
// После вставки высота левого поддерева выросла.
// Результат true, если после вставки и балансировки высота
// всего дерева увеличилась, и false иначе.
bool AVLTree::balanceInsertToLeft(AVLNode*& root) {
	if (root->balance == 1) {
		root->balance = 0;
		return false;// высота всего дерева не изменилась
	}
	else if (root->balance == 0) {// а здесь дерево в целом выросло
		root->balance = -1; 
		return true;
	}
	else {
		// перестройка дерева для восстановления баланса
		if (root->left->balance < 0) {
			return RRotation(root,0);
		}
		return LRRotation(root,0);
	}
}

bool AVLTree::balanceInsertToRight(AVLNode*& root) {
	if (root->balance == -1) {//дерево справа меньше дерева слева
		root->balance = 0;
		return false;
	}
	else if (root->balance == 0) {
		root->balance = 1;
		return true;
	}
	else {
		if (root->right->balance > 0) {
			return LRotation(root,0);
		}
		return RLRotation(root,0);
	}
}

bool AVLTree::RRotation(AVLNode*& pA,bool type) {
	std::cout << "R-Rotation for pA = " << pA->word << std::endl;

	AVLNode*& pB = pA->left;

	if (type == 0) {
		pA->balance = pB->balance = 0;
	}
	if (type == 1) {
		pA->balance = -1;
		pB->balance = 1;
	}

	// перестраиваем дерево
	pA->left = pB->right;
	pB->right = pA;
	pA = pB;// новый корень дерева – узел B
	return type && !(std::abs(pB->balance)); // высота дерева после вставки и балансировки не изменилась
}

bool AVLTree::LRotation(AVLNode*& pA,bool type) {
	std::cout << "L-Rotation for pA = " << pA->word << std::endl;
	std::cout << "было: " << std::endl;
	printTree();

	AVLNode* pB = pA->right;

	if (type == 0) {
		pA->balance = pB->balance = 0;
	}
	if (type == 1) {
		pA->balance = 1;
		pB->balance = -1;
	}

	pA->right = pB->left;
	pB->left = pA;
	pA = pB;
	std::cout << "стало: " << std::endl;
	printTree();
	return type && !(std::abs(pB->balance));
}

bool AVLTree::LRRotation(AVLNode*& pA,bool type) {
	std::cout << "LR-Rotation for pA = " << pA->word << std::endl;

	AVLNode* pB = pA->left;
	AVLNode* pC = pB->right;

	if (pC->balance < 0) {//вставка в Т2
		pC->balance = pB->balance = 0;
		pA->balance = 1;
	}
	else if (pC->balance > 0) {//вставка в Т3
		pC->balance = pA->balance = 0;
		pB->balance = -1;
	}
	else {// новый узел – это C
		pC->balance = 0;
		pA->balance = 0;
		pB->balance = 0;
	}

	// перестраиваем дерево
	pA->left = pC->right;
	pB->right = pC->left;
	pC->left = pB;
	pC->right = pA;
	pA = pC;// новый корень дерева – узел C
	return type;// высота дерева после вставки и балансировки не изменилась
}

bool AVLTree::RLRotation(AVLNode*& pA,bool type) {
	std::cout << "RL-Rotation for pA = " << pA->word << std::endl;

	AVLNode* pB = pA->right;
	AVLNode* pC = pB->left;

	if (pC->balance > 0) {
		pC->balance = pB->balance = 0;
		pA->balance = -1;
	}
	else if (pC->balance < 0) {
		pC->balance = pA->balance = 0;
		pB->balance = 1;
	}
	else {
		pB->balance = 0;
		pA->balance = 0;
		pC->balance = 0;
	}

	pA->right = pC->left;
	pB->left = pC->right;
	pC->left = pA;
	pC->right = pB;
	pA = pC;
	return type;
}



void AVLTree::deleteE(std::string x) {
	bool res = deleteElem(root, x);
}

bool AVLTree::deleteElem(AVLNode*& root, std::string x) {
	//if (root)std::cout << root->word << std::endl;
	if (!root) {
		return false;
	}

	if (x < root->word) {
		//std::cout << "пошёл налево" << std::endl;
		if (deleteElem(root->left, x)) {
			// если после удаления высота левого поддерева уменьшилась,
			// проверим и восстановим баланс
			return balanceDeleteToLeft(root);
		}
		return false;
	}
	if (x > root->word) {
		//std::cout << "пошёл направо" << std::endl;
		if (deleteElem(root->right, x)) {
			return balanceDeleteToRight(root);
		}
		return false;
	}
	
	if (x == root->word) {
		std::cout << "I want to delete " << x << std::endl;
		if (root->count > 1) {
			//std::cout << "Я тут был\n";
			root->count--;
			return false;
		}
		else {
			AVLNode* tmp = root;
			if (!root->left) {//нет потомка слева, подтянем потомка справа или nullptr, если его нет
				root = root->right;
			}
			else if (!root->right) {
				root = root->left;
			}
			else {//два потомка
				//del2(root->left, nodeToDel);
				AVLNode* maxNode = root->left;

				while (maxNode->right != nullptr) {
					maxNode = maxNode->right;
				}

				AVLNode* newRoot = new AVLNode;
				newRoot->word = maxNode->word;
				newRoot->count = maxNode->count;

				maxNode->count = 1;
				/////////////
				

				bool flag = deleteElem(root, maxNode->word);

				tmp->word = newRoot->word;
				tmp->count = newRoot->count;

				delete newRoot;
				return flag;
			}
			delete tmp;
			return true;
		}
	}
}

bool AVLTree::balanceDeleteToRight(AVLNode*& root) {
	if (root == nullptr) {
		std::cout << "RRRRRRRRRRRR\n";
		return true;
	}
	if (root->balance == 1) {
		root->balance = 0;
		return true;// высота всего дерева  уменьшилась
	}
	else if (root->balance == 0) {//здесь дерево не уменьшилось
		root->balance = -1;
		return false;
	}
	else {
		// перестройка дерева для восстановления баланса
		if (root->left->balance < 0) {
			return RRotation(root, 0);
		}
		if (root->left->balance == 0) {
			return RRotation(root, 1);
		}
		if (root->left->balance > 0) {
			return LRRotation(root, 1);
		}
	}
}

bool AVLTree::balanceDeleteToLeft(AVLNode*& root) {
	//std::cout << "сейчас я в " << root->word << std::endl;
	if (root == nullptr) {
		std::cout << "LLLLLLLLLLLLLLLLLL\n";
		return true;
	}
	if (root->balance == -1) {
		root->balance = 0; //std::cout << "problem in " << root->word << std::endl;
		return true;// высота всего дерева  уменьшилась
	}
	else if (root->balance == 0) {//здесь дерево не уменьшилось
		root->balance = 1; 
		return false;
	}
	else {
		// перестройка дерева для восстановления баланса
		if (root->right->balance > 0) {
			return LRotation(root, 0);
		}
		if (root->right->balance == 0) {
			return LRotation(root, 1);
		}
		if (root->right->balance < 0) {
			return RLRotation(root, 1);
		}
	}
}






