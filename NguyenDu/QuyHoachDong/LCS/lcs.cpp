#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s1, s2;

// traditional.
int lcs(int m, int n) {
	// base case: if either of the 2 strings have NO character left.
	if (m == 0 || n == 0) return 0;

	// if both ends with the same char, we add it to lcs
	if (s1[m - 1] == s2[n - 1]) return 1 + lcs(m - 1, n - 1);

	// if both doesnt end with the same char, there is 2 paths:
	// 1. exclude the current last character of s1
	// 2. exclude the current last character of s2
	// we take the maximum value.
	else return max(lcs(m - 1, n), lcs(m, n - 1));
}

// memoization.
vector<vector<int>> memo;
int lcsm(int m, int n) {
	if (m == 0 || n == 0) return 0;
	if (memo[m][n] != -1) return memo[m][n];

	if (s1[m - 1] == s2[n - 1]) memo[m][n] = 1 + lcsm(m - 1, n - 1);
	else memo[m][n] = max(lcsm(m - 1, n), lcsm(m, n - 1));

	return memo[m][n];
}

int lcsmemo() {
	memo = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
	return lcsm(s1.size(), s2.size());
}

int lcsdp() {
	int m = s1.size(), n = s2.size();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));\

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			cout << dp[i][j] << " ";
		}

		cout << '\n';
	}

	string res = "";
	while (m != 0 && n != 0) {
		if (dp[m][n] == dp[m - 1][n - 1] + 1) { // same as s1[m - 1] == s2[n - 1]
			res = s1[m - 1] + res;

			m -= 1;
			n -= 1;
		} else if (dp[m][n] == dp[m - 1][n]) {
			m -= 1;
		} else {
			n -= 1;
		}
	}
	cout << res << '\n';

	return dp[m][n];
}

int main() {
	// cin >> m >> n;
	cin >> s1 >> s2;

	// cout << lcs(s1.size(), s2.size());
	cout << lcsdp();

	return 0;
}