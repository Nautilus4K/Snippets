// Chọn ĐTQG Quảng Trị 2022 - Chọn tranh
// https://oj.clue.edu.vn/problem/qt_tst_22_a
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("CHONTR.INP", "r", stdin);
	freopen("CHONTR.OUT", "w", stdout);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int p, q, r;
	cin >> p >> q >> r;

	// Now I am gonna get all the positions of values that equals to P, Q, R
	vector<int> px, qx, rx;
	px.reserve(n);
	qx.reserve(n);
	rx.reserve(n);

	for (int i = 0; i < n; i++) {
		if (a[i] == p) px.push_back(i);
		if (a[i] == q) qx.push_back(i);
		if (a[i] == r) rx.push_back(i);
	}
	
	/*
	for (const int& x : px) cout << x << " ";
	cout << '\n';
	for (const int& x : qx) cout << x << " ";
	cout << '\n';
	for (const int& x : rx) cout << x << " ";
	cout << '\n';
	*/

	// With Q is the pivot
	// I gotta find how many P is smaller and R is bigger
	long long c = 0;
	for (const int& qr : qx) {
		// First with P
		int smolIndex = lower_bound(px.begin(), px.end(), qr) - px.begin() - 1;
		if (smolIndex < 0 || px[smolIndex] >= qr) continue;

		// cout << qr << " " << smolIndex + 1;
		int smolVal = smolIndex + 1;
		
		// Now with R
		int bigIndex = upper_bound(rx.begin(), rx.end(), qr) - rx.begin();
		if (bigIndex >= rx.size() || rx[bigIndex] <= qr) continue;

		// cout << " " << rx.size() - bigIndex << '\n';
		int bigVal = rx.size() - bigIndex;

		c += smolVal * bigVal;
	}

	cout << c;

	return 0;
}
