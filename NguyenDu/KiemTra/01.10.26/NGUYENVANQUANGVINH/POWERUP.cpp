#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("POWERUP.INP", "r", stdin);
	freopen("POWERUP.OUT", "w", stdout);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> mcd(n + 1);
	mcd[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mcd[i + 1] = mcd[i] + a[i];
	}

	// int start = 0;
	int start = 0;
	int maxv = a[0];
	for (int end = 0; end < n; end++) {
		// kiem tra ton tai trong khoang gtri
		// cout << start << ":" << end << '\n';
		if (end - start + 1 > 1) {
			vector<int>::iterator it = lower_bound(a.begin() + start, a.begin() + end - 1, a[end]);

			if (it != a.end() && *it == a[end]) {
				// start = exts[a[end]] + 1;
				// cout << "lower bound found";
				start = it - a.begin() + 1;
			}
		}

		int tonght = mcd[end + 1] - mcd[start];
		if (tonght < 0) start = end + 1;

		maxv = max(maxv, tonght);
	}

	cout << maxv;

	return 0;
}