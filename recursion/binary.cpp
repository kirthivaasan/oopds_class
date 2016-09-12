#include <iostream>
#include <vector>
#include <set>
using namespace std;

void bina(int dec) {
	if (dec == 0 || dec == 1) {
		cout << dec;
	} else {
		bina(dec/2);
		cout << dec % 2;
	}
}

template <typename T>
void printVector(vector<T> & something) {
	for(int i = 0; i < something.size(); i++)
		cout << something[i];
	cout << endl;
}

void printBinaryHelper(const int &n, vector<int> &decisions, const int &base) {
	// base case
	if (n == decisions.size()) {
		// i have made my decisions
		printVector(decisions);
	} else {
		for (int i = 0; i < base; i++) {
			// pick
			decisions.push_back(i);
			// explore
			printBinaryHelper(n, decisions, base);
			// unpick -- BACKTRACKING MAGIC	
			decisions.pop_back();
		}		
	}
}

void brute(int n, int base) {
	vector<int> decisions;
	printBinaryHelper(n, decisions, base);
}

template <typename T>
bool containsDuplicate(vector<T> &something, T target) {
	int n = 0;
	for (int i = 0; i < something.size(); i++) {
		if (n > 0) return true;
		if (something[i] == target) n++;
	}
	return false;
}

void permuteHelper(const string &word, vector<char> &decisions) {
	if (word.length() == decisions.size()) {
		printVector(decisions);
	} else {
		for (int i = 0; i < word.length(); i++) {
			decisions.push_back(word[i]);
			if (!containsDuplicate(decisions, word[i])) {
				permuteHelper(word, decisions);
			}
			decisions.pop_back();
		}
	}
	
}

void permute(string word) {
	vector<char> decisions;
	permuteHelper(word, decisions);
}

int main() {
	brute(8, 2);
	//permute("ABC");
}