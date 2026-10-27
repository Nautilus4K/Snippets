#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s1, s2;

int lcs() {
	int m = s1.size(), n = s2.size();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m][n];
}

int main() {
	// cin >> m >> n;
	cin >> s1 >> s2;

	// cout << lcs(s1.size(), s2.size());
	long long mutuals = lcs();
	long long size = min(s1.size(), s2.size());
	long long diff = abs((long long)s2.size() - (long long)s1.size());

	cout << size - mutuals + diff;

	return 0;
}