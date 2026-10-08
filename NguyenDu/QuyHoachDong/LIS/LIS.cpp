#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> dp;
	//dp.reserve(n);	
	 
	/*
	for (const int& x : a) {
		vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), x);

		if (it == dp.end()) {
			dp.push_back(x);
		} else {
			*it = x;
		}
	}*/

	dp.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (a[i] > dp.back()) {
			dp.push_back(a[i]);
		} else {
			int low = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
			dp[low] = a[i];
		}
	}
	
	cout << dp.size();

	return 0;
}
