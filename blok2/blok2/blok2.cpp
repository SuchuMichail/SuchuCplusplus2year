// blok2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Queue.h"
#include "Iterator.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    Queue och(3);
    och.push(2);
    och.push(3);
    och.push(4);
    och.print();
    och.pop();
    och.push(8);
    och.print();
    

    printf("%d\n", och.getHead());
    printf("%d\n", och.getPointerHead());
    printf("%d\n\n", och.getPointerTail());

    Iterator iter (och);
    iter.start();
    while (!iter.finish()) {
        std::cout << iter.getValue() << std::endl;
        iter.next();
    }
    std::cout << iter.getValue() << std::endl;
}
