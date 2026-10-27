#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k; long long s;
	cin >> n >> k >> s;

	// vector<vector<long long>> a(n, vector<long long>(m));
	vector<vector<long long>> pref(n + 1, vector<long long>(n + 1));
	int x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// cin >> a[i][j];
			cin >> x;

			pref[i][j] = x + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}

	// cout << "C\n";
	long long ans = 0;
	for (int x1 = 1; x1 <= n - k + 1; x1++) {
		int x2 = x1 + k - 1;

		for (int y1 = 1; y1 <= n - k + 1; y1++) {
			int y2 = y1 + k - 1;

			long long sum = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
			// cout << x1 << "," << y1 << " " << x2 << "," << y2 << " -> " << sum << '\n';

			if (sum >= s) ans++;
		}
	}

	cout << ans;

	return 0;
}