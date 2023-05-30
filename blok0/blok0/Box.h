#pragma once

#include <iostream>
#include <algorithm>
namespace box_space {
    class Box
    {
        friend bool operator==(const Box&, const Box&);
        friend std::ostream& operator<< (std::ostream& out, const Box&);
        friend std::istream& operator>> (std::istream& in, Box&);
        friend bool comp(const Box& a, const Box& b);

    private:
        int length;//длина
        int width;//ширина
        int height;//высота
        double weight;//масса коробки в кг
        int value;//стоимость содержимого в копейках

    public:
        Box();
        Box(int, int, int, double, int);
        Box(const Box&);
        ~Box();

        int getLength();
        int getWidth();
        int getHeight();
        double getWeight();
        int getValue();

        void setLength(int);
        void setWidth(int);
        void setHeight(int);
        void setWeight(double);
        void setValue(int);

        static int sum_value(Box mas[], int size);
        static bool proverka_sum_param(Box mas[], int size, int max);
        static double max_weight(Box mas[], int size, int maxV);
        static bool isMatreshka(Box mas[], const int size);

    };
}
