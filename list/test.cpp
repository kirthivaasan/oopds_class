//#include <list>
#include <iostream>
#include "list.h"
using namespace std;

int main() {
	kirthi::list<int> numbers;
	numbers.push_front(345);
	numbers.push_front(456);
	numbers.push_front(567);
	numbers.push_front(768);
	numbers.insert(99999999, 2);
	numbers.print();
	numbers.remove(0);
	cout << endl;
	numbers.print();
	numbers.clear();
	numbers.print();
	cout << endl << "Size: " << numbers.size() << endl;
}