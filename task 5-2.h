#pragma once
#include <iostream>

template<class T>
class table
{
private:
	class subTable;
	subTable* arr;
	int row = 0;
	int col = 0;
	class subTable {
	public:
		T* subArr;
		subTable() {};
		subTable(int size) {
			subArr = new T[size];
		}
		T& operator[](int i) {
			return subArr[i];
		}

		const T& operator[](int i) const {
			return subArr[i];
		}
	};

public:
	table(int _row, int _col) {
		arr = new subTable[_row];
		for (int i = 0; i < _row; i++) {
			arr[i] = subTable(_col);
		}
		row = _row;
		col = _col;
	};

	subTable& operator[](int j) {
		return arr[j];
	}

	const subTable& operator[](int j) const {
		return arr[j];
	}

	const int Size() const {
		return col * row;
	}

	~table() {
		for (int i = 0; i < row; i++) {
			delete[](arr[i].subArr);
		}
		delete[] arr;
	}
};

void task_5_2() {
	table<std::string> test(2, 2);
	test[1][1] = "eee";
	std::cout << test[1][1] << " " << test.Size() << std::endl;
}
