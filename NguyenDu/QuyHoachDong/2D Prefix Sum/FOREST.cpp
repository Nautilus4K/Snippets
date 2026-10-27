#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			pref[i + 1][j + 1] = a[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
		}
	}

	int x1, x2, y1, y2;
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] << '\n';
	}

	return 0;
}