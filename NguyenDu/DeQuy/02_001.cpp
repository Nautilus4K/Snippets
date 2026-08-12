#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dq(const int& n, int d, string& s, vector<bool>& taken) {
	if (d == 0) {
		cout << s << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!taken[i]) {
			s += char(i + '0');
			taken[i] = true;

			dq(n, d - 1, s, taken);
			
			taken[i] = false;
			s.pop_back();
		}
	}
}

int main() {
	int n;
	cin >> n;

	string s = "";
	vector<bool> taken(n + 1);

	dq(n, n, s, taken);

	return 0;
}
