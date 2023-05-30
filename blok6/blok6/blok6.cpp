// blok6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "BinarySearchTree.h"
#include "AVLTree.h"

void simple() {
    BinarySearchTree tree;
    tree.insertWord("c");
    tree.insertWord("d");
    tree.insertWord("d");
    tree.insertWord("d");
    tree.insertWord("b");
    tree.insertWord("a");
    tree.insertWord("a");
    tree.insertWord("a");
    tree.insertWord("e");
    tree.insertWord("e");
    tree.insertWord("f");

    tree.printAlphabet();
    tree.printTree();

    std::cout << "quantity of word 'e' = " << tree.findWord("e") << std::endl;
    std::cout << "quantity of all words = " << tree.quantityWords() << std::endl;

    //tree.deleteWord("d");
    tree.deleteWord("f");
    // tree.deleteWord("a");
     //tree.deleteWord("f");

    tree.printTree();
}

void AVL() {
    AVLTree tree;
    tree.insert("d");
    tree.insert("d");
    tree.insert("d");
    tree.insert("e");
    tree.insert("f");

    tree.insert("a");
    tree.insert("a");
    tree.insert("a");
    tree.insert("b");
    tree.insert("c");
    tree.insert("g");
    tree.insert("h");
    tree.insert("i");
    tree.insert("j");
    tree.insert("k");
    tree.insert("l");

    tree.printTree();
    
    tree.deleteE("c");
    tree.printTree();

    tree.deleteE("l");
    tree.printTree();

    tree.deleteE("i");
    tree.printTree();

    tree.deleteE("h");
    tree.printTree();
}

void AVL2() {
    AVLTree tree;
    tree.insert("a");
    tree.insert("b");
    //tree.insert("c");
    tree.insert("d");
    tree.insert("e");
    tree.insert("f");
    //tree.insert("bb");
    tree.insert("aa");
    tree.insert("ff");

    tree.printTree();

    tree.deleteE("b");

    std::cout << "after delete\n";
    tree.printTree();
}

void AVL3() {
    AVLTree tree;
    tree.insert("a");
    tree.insert("b");
    tree.insert("c");
    tree.insert("d");
    tree.insert("e");
    tree.insert("f");
    tree.insert("bb");
    //tree.insert("aa");
    tree.insert("ff");

    tree.printTree();

    tree.deleteE("b");

    std::cout << "after delete\n";
    tree.printTree();
}


int main()
{
    setlocale(LC_ALL, "Rus");
    
    //simple();
    AVL();
    //AVL2();
    //AVL3();

    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
