#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("CHANLE.INP", "r", stdin);
	freopen("CHANLE.OUT", "w", stdout);

	int n, k;
	cin >> n >> k;

	// vector<int> a(n);
	int x;
	vector<int> mcdc(n + 1), mcdl(n + 1);
	mcdc[0] = mcdl[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x % 2 == 0) {
			mcdc[i] = mcdc[i - 1] + 1;
			mcdl[i] = mcdl[i - 1];
		} else {
			mcdc[i] = mcdc[i - 1];
			mcdl[i] = mcdl[i - 1] + 1;
		}
	}

	int c = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if ((mcdc[j] - mcdc[i - 1]) - (mcdl[j] - mcdl[i - 1]) == k) {
				// cout << i << " " << j << '\n';
				c++;
			}
		}
	}

	cout << c;

	return 0;
}