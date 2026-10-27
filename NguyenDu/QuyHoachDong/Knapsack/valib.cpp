#include <iostream>
#include <vector>
using namespace std;

vector<int> v(1001), w(1001);
int n, m;

int kp() {
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	// each item
	for (int i = 1; i <= n; i++) {
		// each capacity
		for (int j = 1; j <= m; j++) {
			if (w[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i][j - w[i - 1]]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][m];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
	// for (int i = 0; i < n; i++) cin >> w[i];

	cout << kp();

	return 0;
}