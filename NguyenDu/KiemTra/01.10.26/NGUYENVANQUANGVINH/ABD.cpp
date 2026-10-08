#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("ABD.INP", "r", stdin);
	freopen("ABD.OUT", "w", stdout);

	int n;
	cin >> n;
	vector<int> a;

	int x;
	for (int i = 0; i < n; i++) {
		// lam lis cho nhanh len xiu.
		cin >> x;

		vector<int>::iterator it = lower_bound(a.begin(), a.end(), x);
		if (it == a.end()) {
			a.push_back(x);
		} else if (*it != x) {
			// neu ko trung thi them. neu trung thi bo
			a.insert(it, x);
		}
	}

	int q;
	cin >> q;
	for (int qt = 1; qt <= q; qt++) {
		int k; char x;
		cin >> k >> x;
		if (x == 'S') {
			// nho thu k
			cout << a[k - 1];
		} else {
			// L: lon thu k
			cout << a[n - k];
		}
		cout << '\n';
	}

	return 0;
}