#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> a(1e5 + 1);

void sub1() {
	vector<int> dp(n, 1);
	int res = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] >= a[j]) dp[i] = max(dp[i], dp[j] + 1);
		}

		res = max(res, dp[i]);
	}

	cout << res;
}

void sub2() {
	vector<int> liqabc;
	for (int i = 0; i < n; i++) {
		vector<int>::iterator it = upper_bound(liqabc.begin(), liqabc.end(), a[i]);

		if (it == liqabc.end()) {
			liqabc.push_back(a[i]);
		} else {
			*it = a[i];
		}
	}

	cout << liqabc.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("LIQ.INP", "r", stdin);
	freopen("LIQ.OUT", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (n <= 1e3) sub1(); // met vl
	else sub2();

	return 0;
}