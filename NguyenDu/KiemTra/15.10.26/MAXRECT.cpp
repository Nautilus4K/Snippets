#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("MAXRECT.INP", "r", stdin);
	freopen("MAXRECT.OUT", "w", stdout);

	int m, n;
	cin >> m >> n;

	// vector<vector<int>> a(m, vector<int>(n));
	vector<vector<long long>> mcd(m + 1, vector<long long>(n + 1, 0));
	long long rs;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> rs;

			mcd[i][j] = rs + mcd[i - 1][j] + mcd[i][j - 1] - mcd[i - 1][j - 1];
		}
	}

	long long sum = -LLONG_MAX;
	for (int w = 1; w <= m; w++) {
		for (int h = 1; h <= n; h++) {
			for (int x1 = 1; x1 <= m - w + 1; x1++) {
				int x2 = x1 + w - 1;

				for (int y1 = 1; y1 <= n - h + 1; y1++) {
					int y2 = y1 + h - 1;

					sum = max(sum, (mcd[x2][y2] - mcd[x1 - 1][y2] - mcd[x2][y1 - 1] + mcd[x1 - 1][y1 - 1]));
				}
			}
		}
	}

	cout << sum;

	return 0;
}