#include <iostream>
#include <queue>
using namespace std;

int strToInt(const string& s) {
	int n = 0;

	for (const char& x : s) {
		n = (n * 10) + int(x - '0');
	}

	return n;
}

int main() {
	string s;
	priority_queue<int> a;

	while (getline(cin, s)) {
		if (s[0] == '+') {
			a.push(strToInt(s.substr(1)));
		} else if (s == "-") {
			int val = a.top();
			while (a.top() == val) a.pop();
		} // else break;
	}
	
	cout << a.size() << "\n";
	while (!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}

	return 0;
}
