#include <iostream>
using namespace std;

int main() {
	freopen("ChiaKeo.INP", "r", stdin);
	freopen("ChiaKeo.OUT", "w", stdout);

	int n;
	cin >> n;

	long long a[n], mcd[n + 1];
	mcd[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mcd[i + 1] = mcd[i] + a[i];
	}
	
	long long val = 1e18;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			// calculate
			long long x = mcd[i + 1];
			long long y = mcd[j + 1] - mcd[i + 1];
			long long z = mcd[n] - mcd[j + 1];

			// cout << x << " " << y << " " << z << " " << i << " " << j << '\n';

			val = min(val, max(x, max(y, z)) - min(x, min(y, z)));
		}
	}

	cout << val;

	return 0;
}
