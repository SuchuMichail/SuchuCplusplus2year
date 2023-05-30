// blok3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "RealizeList.h"

RealizeList<int> func(RealizeList<int> list) {
    std::cout << "YARE\n";
    return list;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    RealizeList<int> list_first;
    Iterator<int>& iterator = list_first.getIterOnFirstElem();
    list_first.insertElement(5, iterator);
    list_first.insertElement(6, iterator);
    list_first.insertElement(7, iterator);
    list_first.insertElement(8, iterator);

    std::cout << "First list\n";
    list_first.Print();

    std::cout << "Количество элементов = " << list_first.quantityElements() << "\n";

    RealizeList<int> list_second = list_first;
    std::cout << "Second list\n";
    list_second.Print();

    Iterator<int>& findEl = list_second.findFirstOccurrence(6);
    list_second.deleteElement(findEl);
    std::cout << "Second list\n";
    list_second.Print();

    list_second.insertElement(9, findEl);
    std::cout << "Second list\n";
    list_second.Print();
    
    std::cout << "First list\n";
    list_first.Print();

    RealizeList<int> list_third;
    list_third = list_second;
    std::cout << "Third list\n";
    list_third.Print();

    list_third.makeEmpty();
    std::cout << "Third list (make empty)\n";
    list_third.Print();

    list_third = func(list_second);
    std::cout << "Third list\n";
    list_third.Print();

    RealizeList<int> list_fourth = func(list_third);
    std::cout << "Fourth list\n";
    list_third.Print();

    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
