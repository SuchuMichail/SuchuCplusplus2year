#pragma once
template<typename T>
class Iterator
{
public:
	virtual void start() = 0;
	virtual T getCurrentData() const = 0;
	virtual void moveNext() = 0;
	virtual bool isAll() const = 0;
};

