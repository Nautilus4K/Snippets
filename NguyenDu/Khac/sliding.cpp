#include <iostream>
#include <deque>
#include <vector>
// #include <queue>
using namespace std;

void mondeque(const int& n, const int& k, const vector<int>& a) {
	deque<int> dq;

	for (int i = 0; i < n; i++) {
		// Remove elements outside of window at front
		while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

		// Remove elements <= a[i] at back to keep monotonic
		while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();

		dq.push_back(i);

		// After already populated the initial dq by adding the first k elements
		if (i >= k - 1) cout << a[dq.front()] << ' ';
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	mondeque(n, k, a);

	return 0;
}
