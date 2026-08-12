// #include <cstdlib>
#include <algorithm>
// #include <>
#include <climits>
#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

void dq(int d, const vector<long long>& x, long long& lowest, int start, const long long& xsum, vector<long long>& xdbg) {
	if (d == 0) {
		// lowest = min(lowest, xsum - removed);
		// Good god.
		long long lowestCurrent = INT_MAX;
		int prev = x[0];
		for (int i = 1; i < x.size(); i++) {
			if (!xdbg[i]) {
				long long l = abs(x[i] - prev);

				lowestCurrent = min(lowestCurrent, l);

				prev = x[i];
			}
		}

		// for (const long long& k : xdbg) cout << k << " ";
		// cout << " -> " << lowestCurrent << "\n";

		lowest = max(lowestCurrent, lowest);

		return;
	}

	for (int i = start; i < x.size(); i++) {
		// removed += x[i];
		// xdbg.push_back(x[i]);
		xdbg[i] = true;
		
		// cout << "-" << x[i] << '\n';
		dq(d - 1, x, lowest, i + 1, xsum, xdbg);
		// cout << "+" << x[i] << '\n';
	
		// xdbg.pop_back();
		xdbg[i] = false;
		// removed -= x[i];
	}
}

int main() {
	freopen("BAI2.INP", "r", stdin);
	freopen("BAI2.OUT", "w", stdout);

	int n, c;
	cin >> n >> c;

	vector<long long> x(n); // Alrighty alrighty
	long long xsum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		xsum += x[i];
	}

	sort(x.begin(), x.end());

	int r = n - c;
	
	long long lowest = -INT_MAX;
	long long removed = 0;

	vector<long long> xdbg(n, false);

	dq(r, x, lowest, 0, xsum, xdbg);

	cout << lowest;

	return 0;
}
