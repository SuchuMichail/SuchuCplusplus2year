#pragma once
#include <iostream>
#include "Queue.h"

class Iterator
{
private:
	const Queue& que;
	int pointer;

public:
	Iterator(const Queue& q);
	~Iterator();
	void start();
	void next();
	bool finish() const;
	int getValue() const;
};

