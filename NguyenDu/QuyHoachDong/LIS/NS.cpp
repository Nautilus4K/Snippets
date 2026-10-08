#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first != b.first) return a.first < b.first;
		else return a.second > b.second;
	});

	// vector<int> dp(n, 1);
	// dp.reserve(n);
	// int val = 1;
	
	vector<int> lis;
	for (int i = 0; i < n; i++) {
		// for (int j = 0; j < i; j++) {
		// 	if (a[i].first > a[j].first && a[i].second > a[j].second) dp[i] = max(dp[i], dp[j] + 1);
		// }

		// val = max(val, dp[i]);
		vector<int>::iterator it = upper_bound(lis.begin(), lis.end(), -a[i].second);
		if (it == lis.end()) lis.push_back(-a[i].second);
		else *it = -a[i].second;
	}
	
	cout << lis.size();

	return 0;
}
