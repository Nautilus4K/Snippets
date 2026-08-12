#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<long long> dp(n);
	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);

	for (int i = 2; i < n; i++) {
		dp[i] = min(dp[i - 1] + abs(a[i - 1] - a[i]), dp[i - 2] + abs(a[i - 2] - a[i]));
		// if (dp[i - 1] < dp[i - 2]) dp[i] = dp[i - 1]
	}

	// for (const long long& x : dp) cout << x << " ";
	// cout << '\n';

	cout << dp.back();

	return 0;
}
