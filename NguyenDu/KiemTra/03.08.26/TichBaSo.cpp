#include <bits/stdc++.h>
using namespace std;

int biggestInRange() {
}

int main() {
	freopen("TichBaSo.INP", "r", stdin);
	freopen("TichBaSo.OUT", "w", stdout);

	int n;
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	long long x, y, z;
	cin >> x >> y >> z;
	
	// cout << "GOT " << (n <= 200) << '\n';
	// Split a into sqrt(a) precomputed sections that return which element has the highest value.
	if (n <= 200 && false) {
		// cout << "A\n";
		long long res = -LLONG_MAX;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					long long s = x * a[i] + y * a[j] + z * a[k];
					res = max(res, s);
				}
			}
		}

		cout << res;
	} else { // greedy as fuck
		pair<long long, int> first = {-2e9, -1}, second = {-2e9, -1}, third = {-2e9, -1};

		for (int i = 0; i < n; i++) {
			if (a[i] > first.first) {
				third = second;
				second = first;

				first.first = a[i];
				first.second = i;
			} else if (a[i] > second.first) {
				third = second;

				second.first = a[i];
				second.second = i;
			} else if (a[i] > third.first) {
				third.first = a[i];
				third.second = i;
			}
		}
		
		int i, j, k;
		if (first.second < second.second && first.second < third.second) {
			i = first.second;
			
			if (second.second < third.second) {
				j = second.second;
				k = third.second;
			} else {
				j = third.second;
				k = second.second;
			}
		} else if (second.second < first.second && second.second < third.second) {
			i = second.second;

			if (first.second < third.second) {
				j = first.second;
				k = third.second;
			} else {
				j = third.second;
				k = first.second;
			}
		} else {
			i = third.second;

			if (second.second < first.second) {
				j = second.second;
				k = first.second;
			} else {
				j = first.second;
				k = second.second;
			}
		}

		cout << x * a[i] + y * a[j] + z * a[k];
	} 
	/*else {
		vector<long long> ax(int(sqrt(n)) + 1, -1e9);
		for (int i = 0; i < n; i++) {
			int desg = sqrt(i);
			ax[desg] = max(ax[desg], a[i]);
		}
	}*/
	
	return 0;
}
