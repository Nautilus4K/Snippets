#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	// cout << n << " " << x << "\n";

	vector<pair<int, int>> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i].first;
		t[i].second = i;
	}
	// for (int q : t) cout << q << " ";
	// cout << '\n';

	// cout << "\nAAA\n";
	vector<pair<int, pair<int, int>>> a, b; // mitm
	// int k1 = n / 2, k2 = n - k1;
	for (int i = 0; i < (n / 2) - 1; i++) {
		if (t[i].first > x) continue;
		for (int j = i + 1; j < n / 2; j++) {
			if (t[i].first + t[j].first <= x) a.push_back({t[i].first + t[j].first, {t[i].second, t[j].second}});
		}
	}

	for (int i = n / 2; i < n - 1; i++) {
		if (t[i].first > x) continue;
		for (int j = i + 1; j < n; j++) {
			if (t[i].first + t[j].first <= x) b.push_back({t[i].first + t[j].first, {t[i].second, t[j].second}});
		}
	}

	sort(b.begin(), b.end());
	int wx = 0;
	for (pair<int, pair<int, int>> w : a) {
		// int c = upper_bound(b.begin(), b.end(), x - w) - lower_bound(b.begin(), b.end(), x - w);
		vector<pair<int, pair<int, int>>>::iterator it = lower_bound(b.begin(), b.end(), x - w.first, [](pair<int, pair<int, int>> sum, int val) {
			return sum.first < val;
		});

		if (it != b.end()) {
			if ((*it).first == x - w.first) {
				cout << w.second.first + 1 << " " << w.second.second + 1 << " " << (*it).second.first + 1 << " " << (*it).second.second + 1;
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}