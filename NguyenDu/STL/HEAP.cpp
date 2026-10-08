#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> a;
	int x;
	while (n--) {
		cin >> x;
		a.push(x);
	}

	while (!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}
}
