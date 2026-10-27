#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long itv(long long n) {
	long long v = 1;

	while (n > 0) {
		v *= (n % 10);
		n /= 10;
	}

	return v;
}

int main() {
	freopen("DAYCON.INP", "r", stdin);
	freopen("DAYCON.OUT", "w", stdout);

	int n;
	cin >> n;

	vector<pair<long long, long long>> a(n);

	long long x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[i] = {x, itv(x)};
	}

	// for (auto __a : a) cout << __a.first << " " << __a.second << "\n";

	// vector<pair<long long, long long>> lis;
	// for (const auto& ns : a) {
	// 	vector<pair<long long, long long>>::iterator it = lower_bound(lis.begin(), lis.end(), ns.first, [](const pair<long long, long long>& r, const long long& v) {
	// 		return v > r.first;
	// 	});

	// 	if (it == lis.end()) {
	// 		lis.push_back(ns);
	// 		// cout << "pb: " << ns.first << "," << ns.second << '\n';
	// 	} else {
	// 		if ((*it).second < ns.second) {
	// 			// cout << "rp " << int(it - lis.begin()) << " <- " << ns.first << "," << ns.second << '\n';
	// 			*it = ns;
	// 		}
	// 	}
	// }

	// long long full = 0;
	// for (const auto& lr : lis) full += lr.second;
	// cout << full;

	// the other way to solve this
	vector<long long> dp(n);
	for (int i = 0; i < n; i++) dp[i] = a[i].second;

	long long res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i].first > a[j].first) dp[i] = max(dp[i], dp[j] + a[i].second);
		}

		res = max(res, dp[i]);
	}

	cout << res;

	return 0;
}