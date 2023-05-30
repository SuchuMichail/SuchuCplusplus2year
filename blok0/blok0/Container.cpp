#include "Container.h"
namespace container_space {

	Container::Container() {
		length = 0;
		width = 0;
		height = 0;
		maxWeight = 0;
	}

	Container::Container(int l, int w, int h, double m) {
		length = l;
		width = w;
		height = h;
		maxWeight = m;
	}

	Container::~Container() {
		length = 0;
		width = 0;
		height = 0;
		maxWeight = 0;
		boxes.clear();
	}


	//задание 11

	int Container::quantityBox() {
		return boxes.size();
	}

	int Container::sumLength() {
		int sum = 0;
		for (auto i = 0; i < boxes.size(); i++) {
			sum += boxes.at(i).getLength();
		}
		return sum;
	}
	int Container::sumWidth() {
		int sum = 0;
		for (auto i = 0; i < boxes.size(); i++) {
			sum += boxes.at(i).getWidth();
		}
		return sum;
	}
	int Container::sumHeight() {
		int sum = 0;
		for (auto i = 0; i < boxes.size(); i++) {
			sum += boxes.at(i).getHeight();
		}
		return sum;
	}

	double Container::sumWeight() {
		double sum = 0;
		for (auto i = 0; i < boxes.size(); i++) {
			sum += boxes.at(i).getWeight();
		}
		return sum;
	}

	int Container::sumValue() {
		int sum = 0;
		for (auto i = 0; i < boxes.size(); i++) {
			sum += boxes.at(i).getValue();
		}
		return sum;
	}

	box_space::Box Container::getBox(const int poz) {
		return boxes.at(poz);
	}

	void Container::insertPoz(const int poz, const box_space::Box& box) {
		auto iter = boxes.cbegin();
		boxes.emplace(iter + poz, box);
	}

	void Container::deletePoz(const int poz) {
		auto iter = boxes.cbegin();
		boxes.erase(iter + poz);
	}

	int Container::insertBack(box_space::Box box) {
		int res = 0;
		if (sumWeight() + box.getWeight() <= maxWeight && sumLength() + box.getLength() <= length && 
			sumWidth() + box.getWidth() <= width && sumHeight() + box.getHeight() <= height) {
			boxes.push_back(box);
			res = boxes.size() - 1;
		}
		else {
			throw IsException();
		}
		return res;
	}

	//задание 12
	std::ostream& operator<< (std::ostream& out, const Container& container) {
		out << "length = " << container.length << "\nwidth = " << container.width << "\nheight = " << container.height
			<< "\nweight = " << container.maxWeight << "\n";
		for (auto i = 0; i < container.boxes.size(); i++) {
			out << "Box [" << i << "] :\n" << container.boxes.at(i) << "\n";
		}
		return out;
	}
	std::istream& operator>> (std::istream& in, Container& container) {
		in >> container.length;
		in >> container.width;
		in >> container.height;
		in >> container.maxWeight;
		return in;
	}

	//задание 13
	box_space::Box& Container::operator[](int index) {
		return boxes[index];
	}

}