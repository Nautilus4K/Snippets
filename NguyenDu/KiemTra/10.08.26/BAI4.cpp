#include <climits>
// #include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void dq(const vector<vector<int>>& a, long long& best, int currentCity, long long& current, set<int>& taken, const vector<int>& s) {
	// bool foundCity = false;
	// for (const int& b : a[currentCity]) cout << b << " ";
	// return;

	for (const int& b : a[currentCity]) {
		if (!taken.count(b)) {
			taken.insert(b);
			current += s[b - 1];

			dq(a, best, b, current, taken, s);
			
			current -= s[b - 1];
			taken.erase(b);
		}
	}

	best = max(best, current);
}

int main() {
	freopen("BAI4.INP", "r", stdin);
	// freopen("BAI4.OUT", "w", stdout);

	int n;
	cin >> n;

	vector<int> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	// vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> a(n + 1);
	for (int q = 0; q < n - 1; q++) {
		int i, j;
		cin >> i >> j;

		// cout << i << " " << j << " " << a[i].size() << " " << a[j].size() << "\n";

		a[i].push_back(j);
		a[j].push_back(i);

		// for (const int& o : a[i]) cout << o << " ";
		// cout << '\n';
		// for (const int& o : a[j]) cout << o << " ";
		// cout << '\n';

		// a[5].size();
	}
	
	long long best = -INT_MAX;
	for (int i = 1; i <= n; i++) {
		long long current = 0;
		set<int> taken;
		dq(a, best, i, current, taken, s);
	}
	cout << best;

	return 0;
}
