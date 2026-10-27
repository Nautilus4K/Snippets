#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, h, w;
	cin >> n >> m >> h >> w;

	// vector<vector<long long>> a(n, vector<long long>(m));
	vector<vector<long long>> pref(n + 1, vector<long long>(m + 1));
	int x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// cin >> a[i][j];
			cin >> x;

			pref[i][j] = x + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}

	// cout << "C\n";
	long long ans = 1e18;
	for (int x1 = 1; x1 <= n - h + 1; x1++) {
		int x2 = x1 + h - 1;

		for (int y1 = 1; y1 <= m - w + 1; y1++) {
			int y2 = y1 + w - 1;

			long long sum = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
			// cout << x1 << "," << y1 << " " << x2 << "," << y2 << " -> " << sum << '\n';

			ans = min(ans, sum);
		}
	}

	cout << ans;

	return 0;
}