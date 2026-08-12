#include <iostream>
#include <vector>
using namespace std;

long long res = 0;

void dq(const vector<int>& a, const int& n, int start, const int& k, const vector<int>& v, long long& tong, long long& gt) {
	// long long tong = 0;
	// for (const int& x : b) tong += a[x];
	if (tong > k) {
		return;
	}

	res = max(res, gt);

	for (int i = start; i < n; i++) {
		// b.push_back(i);
		tong += a[i];
		gt += v[i];

		dq(a, n, i + 1, k, v, tong, gt);

		// b.pop_back();
		gt -= v[i];
		tong -= a[i];
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n), v(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> v[i];

	
	vector<int> b;
	long long tong = 0;
	long long gt = 0;
	// cout << "DQ\n";
	dq(a, n, 0, k, v, tong, gt);

	cout << res;

	return 0;
}
