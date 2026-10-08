#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("PLAY.INP", "r", stdin);
	// freopen("PLAY.OUT", "w", stdout);

	int n, k;
	cin >> n >> k;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	if (k == n) {
		long long gt = 0;
		for (int i = 0; i < n; i++)
			if (a[i] >= 0) gt += a[i];
			
		cout << gt;
	} else {
		// cout << "A\n";
		long long gt = 0;
		for (int i = 0; i < n; ) {
			gt += a[i];

			// cout << i << " " << gt << "\n";
			if (i < n - 1 && a[i + 1] < 0) {
				int j = i + 1;
				// cout << j << " -> ";
				int minVal = -1e9, minPos = -1;
				while (a[j] < 0 && j < n && j - i <= k) {
					// if (j - i > k) break;
					if (a[j] >= minVal) {
						minVal = a[j];
						minPos = j;

					}
					j++;
				}

				// cout << j << " " << minVal << " " << minPos << "\n";
				
				i = minPos;
				continue;
			} 

			i++;
		}

		cout << gt;
	}

	return 0;
}
