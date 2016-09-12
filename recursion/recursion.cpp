#include <iostream>
using namespace std;

// abba
// bb is mirror?

bool check(string s) {
	return s[0] == s[s.length() -1];
}

string snipEdges(string word) {
	string s = "";
	for (int i = 1; i < word.length() - 1; i++)
		s += word[i];
	return s;
}

bool palindrome(string word) {
	if (check(word)) {
		if (word.length() > 1)
			return palindrome(snipEdges(word));
		else
			return true;
	}
	return false;
}


int fib(int n) {
	if (n == 1 || n == 0) return 1;
	return n + fib(n - 1);
}

int fib_iter(int n) {
	int result = 0;
	for(int i = 0; i <= n; i++)
		result += i;
	return result;
}

int main() {
	cout << palindrome("sator arepo tenet opera rotas") << endl; // first latin palindrome
}