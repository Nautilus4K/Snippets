#include <iostream>
#include <vector>
using namespace std;

vector<int> v(1001), w(1001);
int n, m;

pair<int, vector<int>> kpn() {
	vector<vector<pair<int, vector<int>>>> dp(n + 1, vector<pair<int, vector<int>>>(m + 1, {0, vector<int>()}));

	// each item
	for (int i = 1; i <= n; i++) {
		// each capacity
		for (int j = 1; j <= m; j++) {
			// if (w[i - 1] <= j) {
			// 	dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
			// } else {
			// 	dp[i][j] = dp[i - 1][j];
			// }

			dp[i][j] = dp[i - 1][j];

			if (w[i - 1] <= j) {
				if (dp[i - 1][j].first <= (v[i - 1] + (dp[i - 1][j - w[i - 1]].first))) {
					dp[i][j] = {v[i - 1] + (dp[i - 1][j - w[i - 1]].first), dp[i - 1][j - w[i - 1]].second};
					dp[i][j].second.push_back(i);
				}
			}
		}
	}

	return dp[n][m];
}

// the original approach
vector<vector<int>> kpdp() {
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	// each item
	for (int i = 1; i <= n; i++) {
		// each capacity
		for (int j = 1; j <= m; j++) {
			if (w[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp;
}

pair<int, vector<int>> printkp() {
	// from the dp table, we find the included values
	vector<vector<int>> dp = kpdp();

	int j = m, val = dp[n][m];

	vector<int> ans;
	for (int i = n; i > 0; i--) {
		// each items, from right to left

		// there are only 2 possibilties of the source of the current item value:
		// 1. excluded: dp[i - 1][j]                          (1)
		// 2. included: v[i - 1] + dp[i - 1][j - w[i - 1]]    (2)
		// this can be find from the logic in kpdp().
		// which means, (1) = val OR (2) = val!!!
		if (dp[i - 1][j] != val) {
			j -= w[i - 1];
			val -= v[i - 1];

			ans.push_back(i);
		}
	}

	return {dp[n][m], ans};
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) cin >> w[i];

	pair<int, vector<int>> res = printkp();
	cout << res.first << '\n';
	for (const int& x : res.second) cout << x << ' ';

	return 0;
}