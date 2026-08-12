#include <iostream>
using namespace std;

string dao(string s, int n) {
	if (n == 0) return string(1, s[0]);
	else return s[n] + dao(s, n - 1);
}

int main() {
	string s;
	cin >> s;

	cout << dao(s, s.size() - 1);
	return 0;
}
