#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	// Sorrie.
	vector<long long> dp(n);
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		long long x = LLONG_MAX;
		for (int j = i - 1; j >= 0 && i - j <= k; j--) {
			// dp[i] = min(dp[j] + abs(a[i] - a[j]), dp[i]);
			x = min(x, dp[j] + abs(a[i] - a[j]));
		}

		dp[i] = x;
	}

	cout << dp.back();

	return 0;
}