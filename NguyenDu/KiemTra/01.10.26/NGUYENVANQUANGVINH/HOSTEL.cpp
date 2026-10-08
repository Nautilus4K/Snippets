#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("HOSTEL.INP", "r", stdin);
	freopen("HOSTEL.OUT", "w", stdout);

	int q, k;
	cin >> q >> k;
	priority_queue<long long> h;
	for (int t = 1; t <= q; t++) {
		int type;
		cin >> type;

		if (type == 1) {
			// them hostel
			long long x, y;
			cin >> x >> y;

			long long dist = (x * x) + (y * y);
			// cout << "1. " << dist << "\n";
			if (h.empty() || (h.top() > dist)) {
				if (h.size() == k) h.pop();
				h.push(dist);
			}
		} else if (type == 2) {
			cout << h.top() << '\n';
		}
	}

	return 0;
}