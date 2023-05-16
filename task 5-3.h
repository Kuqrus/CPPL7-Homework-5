#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class functor {
private:
	std::vector<int> vec;
	int sum, count;

public:
	functor(int size);

	void operator()();

	int getSum();

	int getCount();

	void print();
};

void task_5_3();