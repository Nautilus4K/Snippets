#include <iostream>
using namespace std;

bool dx(const string& s, int i) {
	if (i == 0) if (s[0] == s[s.size() - 1]) return true;

	if (s[i] == s[s.size() - 1 - i]) return dx(s, i - 1);
	else return false;
}

int main() {
	string s;
	cin >> s;
	cout << (dx(s, (s.size() - 1) / 2) ? "YES" : "NO");

	return 0;
}
