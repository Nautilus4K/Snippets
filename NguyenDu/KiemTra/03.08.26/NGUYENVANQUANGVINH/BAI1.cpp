#include <bits/stdc++.h>
using namespace std;

bool snto(int n) {
	if (n == 0 || n == 1) return false;
	
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

void hv(const vector<int>& a, vector<bool>& taken, vector<int>& built, int& d) {
	if (built.size() == a.size()) {
		// Hoan vi hoan thanh
		// Reconstruct
		int n = 0;
		for (const int& x : built) n = (n * 10) + x;

		if (snto(n)) {
			// cout << n << '\n';
			d++;
		}

		return;
	}

	for (int i = 0; i < a.size(); i++) {
		if (!taken[i]) {
			built.push_back(a[i]);
			taken[i] = true;

			hv(a, taken, built, d);
			
			taken[i] = false;
			built.pop_back();
		}
	}
}

int main() {
	freopen("BAI1.INP", "r", stdin);
	freopen("BAI1.OUT", "w", stdout);

	int n;
	cin >> n;

	vector<int> a;
	while (n > 0) {
		a.push_back(n % 10);
		n /= 10;
	}

	vector<bool> taken(a.size(), false);
	vector<int> built;
	built.reserve(a.size());
	int d = 0;
	
	hv(a, taken, built, d);

	cout << d;

	return 0;
}
