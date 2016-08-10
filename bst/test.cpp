#include "bst.h"
#include <iostream>
using namespace std;

int main() {
	kirthi::bst<int> numbers;
	numbers.insert(5);
	numbers.insert(7);
	numbers.insert(9);
	numbers.insert(6);
	numbers.insert(2);
	numbers.insert(4);
	
	numbers.print();
	numbers.remove(7);
	numbers.print();
	numbers.clear();
	cout << "After clearing: " << endl;
	numbers.print();
}