#include <iostream>
#include <vector>
using namespace std;
int n, l;
vector<int> a;

// find most efficient range from 0 -> idx
// vector<int> memo;
// int recef(int idx) {
// 	// cout << idx << '\n';
// 	if (idx == 0) return a[0];
// 	else if (idx < 0) return 0;

// 	if (memo[idx] != -1) return memo[idx];

// 	memo[idx] = max(a[idx] + recef(idx - 1 - l), recef(idx - 1));
// 	return memo[idx];
// }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("CHARGE.INP", "r", stdin);
	freopen("CHARGE.OUT", "w", stdout);

	cin >> n >> l;
	a = vector<int>(n);

	for (int i = 0; i < n; i++) cin >> a[i];


	// recursive with memoization? nah
	// memo = vector<int>(n, -1);
	// cout << recef(n - 1);

	// or nvm i am gonan go dp?
	vector<int> dp(n, 0);
	// dp[0] = a[0];
	for (int i = 0; i < n; i++) {
		if (i - 1 - l >= 0) dp[i] = max(dp[i - 1], a[i] + dp[i - 1 - l]);
		else dp[i] = a[i];
	}

	cout << dp[n - 1];

	// cout << '\n';
	// for (int x : memo) cout << x << " ";
	// cout << '\n';
	// for (int x : dp) cout << x << " ";

	return 0;
}