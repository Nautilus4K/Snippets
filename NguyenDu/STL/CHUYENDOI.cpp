#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	k %= n;

	queue<int> a;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push(x);
	}

	while (k--) {
		x = a.front();
		a.pop();
		a.push(x);
	}

	while (a.size() > 0) {
		cout << a.front() << " ";
		a.pop();
	}
}
