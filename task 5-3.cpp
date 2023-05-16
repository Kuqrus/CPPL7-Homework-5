#include "task 5-3.h"

functor::functor(int size) {
	sum = 0, count = 0;
	std::vector<int>v(size);
	std::for_each(v.begin(), v.end(), [&v](int& i) {
		i = std::rand() % 50 + 1;
		});
	vec = v;
}

void functor::operator()() {
	for (int i : vec) {
		if (i % 3 == 0) {
			count++;
			sum += i;
		}
	}
}

int functor::getSum() {
	return sum;
}

int functor::getCount() {
	return count;
}

void functor::print() {
	std::cout << "Vector contain numbers: ";
	for (int i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void task_5_3() {
	functor test(10);
	test.print();
	test();
	std::cout << "getSum = " << test.getSum() << std::endl;
	std::cout << "getCount = " << test.getCount() << std::endl;
}