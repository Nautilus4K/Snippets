#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	// vector<vector<long long>> a(n, vector<long long>(m));
	vector<vector<long long>> pref(n + 1, vector<long long>(m + 1));
	int rs;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// cin >> a[i][j];
			cin >> rs;

			pref[i][j] = rs + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}

	// cout << "C\n";
	long long ans = 0;
	int dmax = min(n, m);
	for (int d = 1; d <= dmax; d++) {
		for (int x1 = 1; x1 <= n - d + 1; x1++) {
			int x2 = x1 + d - 1;

			for (int y1 = 1; y1 <= m - d + 1; y1++) {
				int y2 = y1 + d - 1;

				long long sumrise = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];

				// ans = min(ans, sum);
				if (sumrise == x) {
					// cout << x1 << "," << y1 << " " << x2 << "," << y2 << " -> " << sumrise << " = " << x << '\n';
					ans++;
				} else {
					// cout << x1 << "," << y1 << " " << x2 << "," << y2 << " -> " << sumrise << '\n';
				}
			}
		}
	}

	cout << ans;

	return 0;
}