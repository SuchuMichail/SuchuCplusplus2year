// blok5_Tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "BinaryTree.h"

BinaryTree fun(BinaryTree tree) {
    return tree;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    BinaryTree tree;

    std::vector<int> v1 = {};
    std::vector<int> v2 = { 0 };
    std::vector<int> v3 = { 1 };
    std::vector<int> v4 = { 0,1 };
    std::vector<int> v5 = { 0,1,0 };
    std::vector<int> v6 = { 0,1,1 };
    std::vector<int> v7 = { 0,0 };

    tree.insertElement(100, v2);
    tree.insertElement(2, v1);
    tree.insertElement(7, v2);
    tree.insertElement(5, v3);
    tree.insertElement(9, v4);
    tree.insertElement(6, v3);
    tree.insertElement(1, v5);
    tree.insertElement(0, v6);//
    tree.insertElement(4, v7);


    tree.printTreeLR();
    tree.printTreeLevel();

    BinaryTree tree2 = tree;
    tree2.printTreeLR();

    BinaryTree tr;
    tr = tree;
    tr.printTreeLR();

    BinaryTree tree3 = fun(tree2);
    tree3.printTreeLR();

    BinaryTree tr4;
    tr4 = fun(tree3);
    tr4.printTreeLR();

    std::cout << "quantity even numbers = " << tree.quantityEvenNumbers() << std::endl;
    std::cout << "only positive numbers: " << tree.onlyPositive() << std::endl;
    std::cout << "arithmetic mean = " << tree.arithmeticMean() << std::endl;
    std::cout << std::endl;

    std::cout << "find 9: ";
    std::vector<int> nine = tree.findElement(9);
    for (int i = 0; i < nine.size(); i++) {
        std::cout << nine[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    tree.deleteAllLeafs();
    tree.printTreeLevel();

    std::cout << std::endl;

    BinaryTree search;
    std::vector<int> s1 = {};
    std::vector<int> s2 = { 0 };
    std::vector<int> s3 = { 1 };
    std::vector<int> s4 = { 0,0 };
    std::vector<int> s5 = { 0,1 };
    std::vector<int> s6 = { 1,0 };
    std::vector<int> s7 = { 0,0,0 };

    std::cout << "isBinaruSearch: " << search.isBinarySearch() << std::endl;

    search.insertElement(4, s1);

    std::cout << "isBinaruSearch: " << search.isBinarySearch() << std::endl;

    search.insertElement(2, s2);
    search.insertElement(9, s3);
    search.insertElement(1, s4);
    search.insertElement(3, s5);
    search.insertElement(6, s6);
    search.insertElement(0, s7);
    search.printTreeLevel();

    std::cout << "isBinaruSearch: " << search.isBinarySearch() << std::endl;

    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
