#include <iostream>
using namespace std;

int main() {
	freopen("KYDIEU.INP", "r", stdin);
	freopen("KYDIEU.OUT", "w", stdout);

	long long n;
	cin >> n;

	long long c = 0;

	for (long long x = 1; x * (x + 1) < n; x++) {
		if (x % 6 == (((x % 6) * (x % 6)) * (x % 6)) % 6) {
			c++;
			// cout << x << " " << x % 6 << " " << x * x * x << " " << (((x % 6) * (x % 6)) * (x % 6)) % 6 << " " << "K" << '\n';
		} else {
			// cout << x << "\n";
		}

		// c++;
	}

	cout << c;

	return 0;
}