#include <iostream>
#include <algorithm>
using namespace std;

int a[1000001];
int n, k;

void solve() {
	sort(a, a + n);

	int is = 0;
	int l = 2;

	// int l1 = 1;
	for (int ie = 0; ie < n - 1; ie++) {
		while (a[ie] - a[is] > k) is++;
		// is = lower_bound(a + is, a + ie, a[ie] - k) - a;

		int l1 = ie - is + 1;

		// with each time this is looped.
		int js = ie + 1;
		int l2 = 1;
		for (int je = ie + 1; je < n; je++) {
			while (a[je] - a[js] > k) js++;
			// is = lower_bound(a + js, a + je, a[je] - k) - a;

			l2 = max(l2, je - js + 1);
		}

		l = max(l, l1 + l2);
	}

	cout << l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("HOA.INP", "r", stdin);
	freopen("HOA.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	solve();

	return 0;
}