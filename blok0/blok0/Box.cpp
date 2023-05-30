#include "Box.h"
namespace box_space {
    Box::Box() {
        length = 0;//длина
        width = 0;//ширина
        height = 0;//высота
        weight = 0;//масса коробки в кг
        value = 0;//стоимость содержимого в копейках
    }

    Box::Box(int length1, int width1, int height1, double weight1, int value1) {
        setLength(length1);
        setWidth(width1);
        setHeight(height1);
        setWeight(weight1);
        setValue(value1);
    }

    Box::Box(const Box& box) {
        length = box.length;
        width = box.width;
        height = box.height;
        weight = box.weight;
        value = box.value;
    }

    int Box::getLength() {
        return length;
    }
    int Box::getWidth() {
        return width;
    }
    int Box::getHeight() {
        return height;
    }
    double Box::getWeight() {
        return weight;
    }
    int Box::getValue() {
        return value;
    }

    void Box::setLength(int l) {
        length = l;
    }
    void Box::setWidth(int wi) {
        width = wi;
    }
    void Box::setHeight(int h) {
        height = h;
    }
    void Box::setWeight(double we) {
        weight = we;
    }
    void Box::setValue(int v) {
        value = v;
    }

    Box::~Box() {
        length = 0;//длина
        width = 0;//ширина
        height = 0;//высота
        weight = 0;//масса коробки в кг
        value = 0;//стоимость содержимого в копейках
    }


    int Box::sum_value(Box mas[], int size) {
        //задание 2
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += mas[i].value;
        }
        return sum;
    }

    bool Box::proverka_sum_param(Box mas[], int size, int max) {
        //задание 3
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += mas[i].length + mas[i].width + mas[i].height;
        }
        return sum <= max;
    }

    double Box::max_weight(Box mas[], int size, int maxV) {
        //задание 4
        double maxWeight = 0;
        for (int i = 0; i < size; i++) {
            if (mas[i].length * mas[i].width * mas[i].height <= maxV && mas[i].weight > maxWeight) {
                maxWeight = mas[i].weight;
            }
        }
        return maxWeight;
    }


    bool comp(const Box& a, const Box& b) {
        return a.value < b.value;
    }
    bool Box::isMatreshka(Box mas[], const int size) {
        //задание 5
        Box* V = new Box[size];
        for (int i = 0; i < size; i++) {
            V[i] = Box(mas[i]);
        }

        for (int i = 0; i < size; i++) {
            V[i].value = mas[i].length * mas[i].width * mas[i].height;
        }

        std::sort(V, V + size, comp);
        /*for (int i = 0; i < size; i++) {
            std::cout << V[i] << std::endl;
        }*/

        bool boo = true;
        for (int i = 0; i < size - 1; i++) {
            if (V[i].length > V[i + 1].length) {
                boo = false;
            }
            else {
                if (V[i].width > V[i + 1].width) {
                    boo = false;
                }
                else {
                    if (V[i].height > V[i + 1].height) {
                        boo = false;
                    }
                }
            }
        }

        delete[] V;
        return boo;
    }


    bool operator==(const Box& a, const Box& b) {
        //задание 6
        return a.length == b.length && a.width == b.width && a.height == b.height
            && a.weight == b.weight && a.value == b.value;
    }

    //задание 7
    std::ostream& operator<< (std::ostream& out, const Box& box) {
        out << "length = " << box.length << "\nwidth = " << box.width << "\nheight = " << box.height
            << "\nweight = " << box.weight << "\nvalue = " << box.value << "\n";
        return out;
    }
    std::istream& operator>> (std::istream& in, Box& box) {
        in >> box.length;
        in >> box.width;
        in >> box.height;
        in >> box.weight;
        in >> box.value;
        return in;
    }
}