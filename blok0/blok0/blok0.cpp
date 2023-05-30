// blok0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Box.h"
#include "Container.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    //задание 8
    const int size = 3;
    std::cout << "Enter\n";
    box_space::Box box1(2, 3, 4, 3, 1);
    box_space::Box box2(3,4,5,5,1);
    box_space::Box box3(4,5,6,4,1);

    box_space::Box mas[size];
    mas[0] = box1;
    mas[1] = box2;
    mas[2] = box3;

    int r2 = box_space::Box::sum_value(mas, size);
    std::cout << r2 << std::endl;//3

    bool r3 = box_space::Box::proverka_sum_param(mas, size, 30);
    std::cout << r3 << std::endl;//true

    double r4 = box_space::Box::max_weight(mas, size, 30);
    std::cout << r4 << std::endl; //ответ 5

    bool r5 = box_space::Box::isMatreshka(mas, size);
    std::cout << r5 << std::endl;//false
    std::cout << "изменилииииииии" << std::endl;

    std::cout << box1 << std::endl;

    box_space::Box one(1, 1, 1, 1, 1);
    box_space::Box two(1, 1, 1, 1, 1);
    bool b = one == two;
    std::cout << (one==two) << std::endl << std::endl;//true


    //задание 14
    std::cout << "Container\n";
    container_space::Container container(7, 9, 15, 20);
    container.insertBack(box1);
    container.insertBack(box3);
    container.insertPoz(1, box2);

    box_space::Box big_box(1, 1, 1, 20, 1);
    try {
        container.insertBack(big_box);
    }
    catch (container_space::Container::IsException e) {
        std::cout << e.s << std::endl;//здесь не смогу добавить тяжёлую коробку
    }

    std::cout << container << std::endl;

    int quantity = container.quantityBox();
    std::cout << quantity << std::endl;//3

    double sum_weight = container.sumWeight();
    std::cout << sum_weight << std::endl;//12

    int sum_value = container.sumValue();
    std::cout << sum_value << std::endl;//3

    std::cout << container[1] << std::endl;//box2
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
