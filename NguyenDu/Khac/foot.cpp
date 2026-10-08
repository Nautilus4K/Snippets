#include <iostream>
#include <deque>
#include <vector>
// #include <queue>
using namespace std;

void mondeque(const int& n, const int& k, const vector<int>& a) {
	deque<int> dq;
	long long cost = 0;

	for (int i = 0; i < n; i++) {
		// Remove elements outside of window at front
		while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

		// Remove elements <= a[i] at back to keep monotonic
		while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();

		dq.push_back(i);

		// After already populated the initial dq by adding the first k elements
		cost += 2 * a[dq.front()];
		// cout << i << " " << a[dq.front()] << '\n';
		// sum += a[dq.front()];
	}

	cout << cost;
}

int main() {
	int m, k;
	cin >> m >> k;

	vector<int> c(m);
	for (int i = 0; i < m; i++) cin >> c[i];

	mondeque(m, k, c);

	return 0;
}
