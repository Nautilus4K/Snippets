#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> r(n), h(n);
	for (int i = 0; i < n; i++) cin >> r[i] >> h[i];

	reverse(r.begin(), r.end());
	reverse(h.begin(), h.end());

	vector<int> dp;
	vector<int> dph;
	dp.reserve(n);
	dph.reserve(n);
	
	for (int i = 0; i < n; i++) {
		vector<int>::iterator it = upper_bound(dp.begin(), dp.end(), r[i]);

		if (it == dp.end()) {
			dp.push_back(r[i]);
			dph.push_back(h[i]);
		} else {
			int pos = int(it - dp.begin());
			// it -= 1;
			dp[pos] = r[i];
			dph[pos] = h[i];
		}
	}
	
	// cout << dp.size();
	int val = 0;
	// for (const int& x : dp) cout << x << " ";
	// cout << '\n';
	for (const int& x : dph) val += x;
	cout << val;

	return 0;
}
