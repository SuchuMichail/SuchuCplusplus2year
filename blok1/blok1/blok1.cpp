// blok1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DynamicArray.h"

DynamicArray fun(DynamicArray mas) {
    return mas;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    DynamicArray arr(3, 5);
    std::cout << arr << std::endl;
    
    DynamicArray oper;
    std::cout << oper << std::endl; //конструктор по умолчанию

    oper = arr; //сработает оператор копирующего присваивания

    DynamicArray copy(arr);
    arr[0] = 1;
    std::cout << arr << std::endl; //массив изменится
    std::cout << oper << std::endl; //другой массив, который был создан копирующим присваиванием, не изменится
    std::cout << copy << std::endl; //копия не изменится
    

    DynamicArray big(5, 1);
    DynamicArray s(3, 1);
    
    std::cout << "operators\n";
    std::cout << (s >= arr) << std::endl << std::endl;//0
    std::cout << (big > s) << std::endl;//1
    std::cout << (big < s) << std::endl;//0

    DynamicArray tes = fun(s);//сработает конструктор перемещения
    
    std::cout << tes << std::endl;
    

    tes = fun(s); //сработает оператор перемещающего присваивания
    std::cout << tes << std::endl;


    tes.resize(5);
    std::cout << "tes изменил размеры\n" << tes << std::endl;
    DynamicArray tester = tes;
    tester.resize(2);
    std::cout << "tes изменил размеры\n" << tester << std::endl;
    tester.resize(5);
    std::cout << "tes изменил размеры\n" << tester << std::endl;
    tester.resize(6);
    std::cout << "tes изменил размеры\n" << tester << std::endl;
    tester.resize(5);
    std::cout << "tes изменил размеры\n" << tester << std::endl;

    std::cout << (s != arr) << std::endl;
    std::cout << (s == arr) << std::endl;

    

    DynamicArray plus = tes + s;
    std::cout << plus << std::endl;//11011


    plus.reserve(3);
    std::cout << plus.getSize() << std::endl;
    std::cout << plus.capacity() << std::endl;

   // std::cout << plus[6] << std::endl;

    std::cout << plus.pushBack(9) << std::endl;
    std::cout << plus.popBack() << std::endl;
    std::cout << plus << std::endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

