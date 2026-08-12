#include <climits>
#include <iostream>
#include <vector>
// #include <map>
using namespace std;

int main() {
	freopen("BAI3.INP", "r", stdin);
	freopen("BAI3.OUT", "w", stdout);

	int n;
	cin >> n;

	// map<int, bool> a;
	vector<pair<int, bool>> a(n);
	vector<int> mcd(n + 1);
	for (int i = 0; i < n; i++) {
		int x; char c;
		cin >> x >> c;

		a[i] = {x, (c == 'B')};

		mcd[i + 1] = mcd[i] + (a[i].second ? 1 : -1);
	}

	// for (const auto& x : a) cout << x.first << " " << x.second << "\n";
	int longest = -INT_MAX;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {	
			// cout << i << " " << j << " " << mcd[j + 1] - mcd[i] << "\n";
			if (mcd[j + 1] - mcd[i] == 0) {
				longest = max(longest, a[j].first - a[i].first);
			}
		}
	}

	cout << longest;

	return 0;
}
