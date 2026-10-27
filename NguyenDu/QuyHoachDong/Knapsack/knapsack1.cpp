#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// function to solve knapsack
// returns the maximum value that can be achieved from a subset of items from 0 to n - 1
// W is remaining capacity, n is limit.
int baloCoNho(const vector<int>& v, const vector<int>& w, int W, int n, vector<vector<int>>& memo) {
	if (W == 0 || n == 0) return 0; // if no more capacity, or we checked all the items, no more value can be added

	if (memo[n][W] != -1) return memo[n][W]; // in case we gone through this b4
	if (w[n - 1] > W) {
		// too heavy, skip. no value added
		memo[n][W] = baloCoNho(v, w, W, n - 1, memo);
		return memo[n][W];
	}

	// branch into 2 instances, get the bigger value, greedy fuck
	memo[n][W] = max(
		v[n - 1] + baloCoNho(v, w, W - w[n - 1], n - 1, memo),  // in case this item gets added.
		baloCoNho(v, w, W, n - 1, memo)  // in case this item gets excluded.
	);
	return memo[n][W];
}

int balo(const vector<int>& v, const vector<int>& w, int W, int n) {
	if (W == 0 || n == 0) return 0; // if no more capacity, or we checked all the items, no more value can be added

	if (w[n - 1] > W) return balo(v, w, W, n - 1); // too heavy, skip. no value added

	return max(
		v[n - 1] + balo(v, w, W - w[n - 1], n - 1),  // in case this item gets added.
		balo(v, w, W, n - 1)  // in case this item gets excluded.
	);
}

int ans = 0;
void baloBacktrack(const vector<int>& v, const vector<int>& w, int W, int V, int idx) {
	ans = max(ans, V);

	if (W == 0 || idx == 0) return;
	for (int i = idx; i >= 0; i--) {
		if (w[i] > W) continue;

		baloBacktrack(v, w, W - w[i], V + v[i], i - 1);
	}

	return;
}

int baloDP(const vector<int>& v, const vector<int>& w, const int& n, const int& m) {
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {

		// iterate over each possible capacity
		for (int j = 1; j <= m; j++) {
			if (w[i - 1] <= j) {
				// if the current item's weight is smaller than the cap
				dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
			} else {
				// too heavy. skip
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= m; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }

	return dp[n][m];
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(n), w(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) cin >> w[i];

	// vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1)); // memoization
	// cout << baloCoNho(v, w, m, n, memo);

	// baloBacktrack(v, w, m, 0, n - 1);
	// cout << ans;

	cout << baloDP(v, w, n, m);

	return 0;
}