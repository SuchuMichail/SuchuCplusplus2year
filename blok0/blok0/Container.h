#pragma once
#include <vector>
#include "Box.h"

namespace container_space {
	class Container
	{
		friend std::ostream& operator<< (std::ostream& out, const Container&);
		friend std::istream& operator>> (std::istream& in, Container&);

	private:
		std::vector<box_space::Box> boxes;
		int length;
		int width;
		int height;
		double maxWeight;

	public:
		struct IsException { std::string s = "Ограничение по весу не выполнено\n"; };

		Container();
		Container(int, int, int, double);
		~Container();

		void insertPoz(const int poz, const box_space::Box& box);
		void deletePoz(const int poz);
		int quantityBox();
		double sumWeight();
		int sumValue();
		int sumLength();
		int sumWidth();
		int sumHeight();
		box_space::Box getBox(const int poz);
		int insertBack(box_space::Box box);
		box_space::Box& operator[](int index);
	};
}
