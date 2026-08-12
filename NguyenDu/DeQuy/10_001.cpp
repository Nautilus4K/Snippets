#include <iostream>
using namespace std;

bool validate(const string& s) {
	int index = 0;

	for (const char& x : s) {
		if (x == '(') index++;
		else index--;

		if (index < 0) return false;
	}

	return (index == 0);
}

void dq(int d, string& s, long long& c) {
	if (d == 0) {
		if (validate(s)) {
			cout << s << '\n';
			c++;
		}
		return;
	}

	char a = '(';
	s.push_back(a);
	// availableOpens++;

	dq(d - 1, s, c);

	s.pop_back();
	// availableOpens--;

	// if (availableOpens > 0) {
	a = ')';
	s.push_back(a);
	// availableOpens--;

	dq(d - 1, s, c);

	// availableOpens--;
	s.pop_back();
}

int main() {
	int n;
	cin >> n;
	
	string s = "";
	long long c = 0;
	dq(n, s, c);

	cout << c;

	return 0;
}
