#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<long long>> a(n, vector<long long>(m));
	vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			pref[i + 1][j + 1] = a[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
		}
	}

	int r1, r2, c1, c2;
	while (q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		cout << pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1] << '\n';
	}

	return 0;
}