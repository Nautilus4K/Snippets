#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	deque<int> rq;
	for (int i = 0; i < n; i++) {
		while (!rq.empty() && rq.front() <= i - k) rq.pop_front();
		while (!rq.empty() && a[rq.back()] >= a[i]) rq.pop_back();

		rq.push_back(i);

		if (i >= k - 1) cout << a[rq.front()] << "\n";
	}

	return 0;
}
