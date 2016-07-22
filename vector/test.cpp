#include <vector>
#include <iostream>
#include "vector.h"
using namespace std;

int main() {
	// Example of stl vector
	vector<int> numbers;
	for (int i = 0; i < 10; i++)
		numbers.push_back(i); // adds 10 numbers into vector
		
	kirthi::vector<int> morenumbers;
	for (int i = 5; i < 10; i++)
		morenumbers.push_back(i); 
	//std::cout << std::endl << "morenumbers.size() = " << morenumbers.size() << std::endl;
	morenumbers.pop_back();
	cout << morenumbers[3] << endl;
}