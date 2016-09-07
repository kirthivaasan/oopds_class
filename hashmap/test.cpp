#include <iostream>
#include "hashmap.h"
using namespace std;

int main() {
	kirthi::hashmap<int, std::string> table;
	
	table.insert(6, "hello");
	table.insert(109, "hello");
	table.print();
	table.remove(109);
	cout << endl << "After removing 109: " << endl << endl; 
	table.print();
	//cout << endl << table.find(109) << endl;
}