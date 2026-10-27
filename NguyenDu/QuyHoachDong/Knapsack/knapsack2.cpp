#include <iostream>
#include <vector>
using namespace std;
int n, m1, m2;
vector<int> a;
// vector<int> w;

// solving double knapsack by recursion
// we try all possible ways to solve 2 knapsacks and get the biggest one possible from
// range (idx -> n - 1)
int knapsack2(int idx, int cap1, int cap2) {
	// all items checked?
	if (idx >= n) return 0;

	// we have 3 options:

	// opt 1. dont take the current item.
	int res = knapsack2(idx + 1, cap1, cap2);

	// opt 2. add to 1st knapsack
	if (a[idx] <= cap1) {
		res = max(res, a[idx] + knapsack2(idx + 1, cap1 - a[idx], cap2));
	}

	// opt 3. add to 2nd knapsack
	if (a[idx] <= cap2) {
		res = max(res, a[idx] + knapsack2(idx + 1, cap1, cap2 - a[idx]));
	}

	return res;
}

// lets rewrite the code above but with memoization!
vector<vector<vector<int>>> memo;
int knapsack2memo(int idx, int cap1, int cap2) {
	if (idx >= n) return 0;

	if (memo[idx][cap1][cap2] != -1) return memo[idx][cap1][cap2];

	int res = knapsack2(idx + 1, cap1, cap2); // 1
	if (a[idx] <= cap1) res = max(res, a[idx] + knapsack2(idx + 1, cap1 - a[idx], cap2));
	if (a[idx] <= cap2) res = max(res, a[idx] + knapsack2(idx + 1, cap1, cap2 - a[idx]));

	return res;
}

int invokeKnapsack2memo() {
	memo = vector<vector<vector<int>>>(n, vector<vector<int>>(m1 + 1, vector<int>(m2 + 1, -1)));
	return knapsack2memo(0, m1, m2);
}

// now, tabulation
int knapsack2dp() {
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m1 + 1, vector<int>(m2 + 1, 0)));

	// with each item
	for (int i = 1; i <= n; i++) {
		// with each capacity for 1st knapsack
		for (int j = 0; j <= m1; j++) { // i = 0 in case we ignore THIS knapsack, for instance
			// same for 2nd knapsack
			for (int k = 0; k <= m2; k++) {
				// opt 1. ignore this item
				dp[i][j][k] = dp[i - 1][j][k];

				// opt 2. 1st knapsack
				if (a[i - 1] <= j) dp[i][j][k] = max(dp[i][j][k], a[i - 1] + dp[i - 1][j - a[i - 1]][k]);

				// opt 3. 2nd knapsack
				if (a[i - 1] <= k) dp[i][j][k] = max(dp[i][j][k], a[i - 1] + dp[i - 1][j][k - a[i - 1]]);
			}
		}
	}

	return dp[n][m1][m2];
}

int main() {
	cin >> n >> m1 >> m2;
	a.resize(n); // w.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	// for (int i = 0; i < n; i++) cin >> w[i];

	cout << knapsack2dp();

	return 0;
}