#include <iostream>
using namespace std;

void dq(int n, string& s) {
	if (n == 0) {
		cout << s << '\n';
		return;
	}

	for (char i = '0'; i <= '1'; i++) {
		s += i;

		dq(n - 1, s);

		s.pop_back();
	}
}

int main() {
	int n;
	cin >> n;

	string s = "";
	dq(n, s);

	return 0;
}
