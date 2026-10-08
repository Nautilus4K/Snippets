#include <iostream>
#include <vector>
using namespace std;

void dq(const vector<int>& a, const int& n, vector<int>& b, int start, const int& k) {
	long long tong = 0;
	for (const int& x : b) tong += a[x];
	if (tong == k) {
		for (const int& x : b) cout << a[x] << " ";
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) {
		b.push_back(i);

		dq(a, n, b, i + 1, k);

		b.pop_back();
	}
}

int main() {
	int n, k;
	cin >> k >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> b;
	dq(a, n, b, 0, k);

	return 0;
}
