#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("BAI1.INP", "r", stdin);
	freopen("BAI1.OUT", "w", stdout);

	int n; long long s;
	cin >> n >> s;

	vector<long long> a(n);
	vector<long long> mcd(n + 1);
	mcd[0] = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mcd[i + 1] = mcd[i] + a[i];
	}

	int l = 0, r = 0;
	int lowCount = INT_MAX;
	while (r < n) {
		if (mcd[r + 1] - mcd[l] >= s) {
			lowCount = min(lowCount, r - l + 1);
			l++;
		} else {
			r++;
		}
	}

	cout << lowCount;

	return 0;
}
