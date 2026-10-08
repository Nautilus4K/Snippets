// #include <algorithm>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> a(501);
int s;
int n;
bool ok = false;

void solve(int idx, int csum) {
	if (csum == s) {
		ok = true;
		return;
	}

	// vector<int>::iterator itl = lower_bound(a.begin() + idx, a.end(), s - csum);
	vector<int>::iterator itu = upper_bound(a.begin() + idx, a.end(), s - csum);

	// int valuecount = itu - itl;
	// if (valuecount > 0) {
	if (itu != a.end() && itu != a.begin()) {
		itu -= 1;
		int index = itu - a.begin();
		solve(idx, csum + *itu);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cin >> s;

	// sort(a.begin(), a.end(), [](const int& a, const int& b) {
	// 	return a > b;
	// });
	for (int i = 0; i < n; i++) solve(i, a[i]);

	cout << (ok ? "YES" : "NO");

	return 0;
}