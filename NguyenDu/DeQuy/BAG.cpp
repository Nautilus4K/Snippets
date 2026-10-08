#include <iostream>
#include <vector>
using namespace std;

void dq(const int& n, const int& m, const vector<int>& w, const vector<int>& v, int start, int& curW, int& curV, int& maxV, vector<int>& trace, vector<int>& maxTrace) {
	// if (d == n) return;
	if (curW > m) return;

	if (curV > maxV) {
		maxV = curV;
		maxTrace = trace;
	}

	if (curW == m) return; // We are ONLY adding up so its best to end the cycle of pain quickly

	for (int i = start; i < n; i++) {
		trace.push_back(i);
		curW += w[i]; curV += v[i];

		dq(n, m, w, v, start + 1, curW, curV, maxV, trace, maxTrace);

		curW -= w[i]; curV -= v[i];
		trace.pop_back();
	}
}

int main() {
	freopen("BAG.INP", "r", stdin);
	// freopen("BAG.OUT", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<int> v(n), w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	int curV = 0, curW = 0, maxV = -2e9;
	vector<int> trace;
	vector<int> maxTrace;

	trace.reserve(n);
	maxTrace.reserve(n);

	dq(n, m, w, v, 0, curW, curV, maxV, trace, maxTrace);
	
	cout << maxV << '\n';
	for (const int& x : maxTrace) cout << x + 1 << " ";

	return 0;
}
