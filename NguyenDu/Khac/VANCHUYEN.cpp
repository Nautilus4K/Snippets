#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool splitable(const long long& cap, const int& k, const vector<long long>& a) {
	long long currentSum = 0;
	int currentArrays = 1;

	for (int i = 0; i < a.size(); i++) {
		currentSum += a[i];

		if (currentSum > cap) {
			currentArrays++;
			currentSum = a[i];

			if (currentArrays > k) return false;
		}
	}

	return true;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<long long> a(n);
	long long sumA = 0;
	long long maxA = -1e9;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sumA += a[i];
		maxA = max(maxA, a[i]);
	}
	// sort(a.begin(), a.end());

	long long l = maxA, r = sumA, ans = sumA;
	while (l <= r) {
		long long m = (l + r) / 2;

		if (splitable(m, k, a)) {
			ans = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	cout << ans;

	return 0;
}
