#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s1, s2;

void lcsdp() {
	int m = s1.size(), n = s2.size();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));\

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[m][n] << '\n';

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
	cout << res;
}

int main() {
	// cin >> m >> n;
	cin >> s1 >> s2;

	// cout << lcs(s1.size(), s2.size());
	lcsdp();

	return 0;
}