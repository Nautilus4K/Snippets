#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> k;
	int n;
	cin >> n;

	int x;
	while(n--) {
		cin >> x;

		if (x % 2 == 0) k.push_back(x);
		else k.push_front(x);
	}

	while (k.size() > 0) {
		cout << k.front() << " ";
		k.pop_front();
	}
}
