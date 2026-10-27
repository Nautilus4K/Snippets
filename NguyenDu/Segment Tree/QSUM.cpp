#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 1e5 + 7
int n;

vector<long long> a(MAX_N + 1);
vector<long long> st(4 * MAX_N);

void build(int iv, int tLeft, int tRight) {
	if (tRight - tLeft == 1) {
		st[iv] = a[tLeft];
	} else {
		int tMid = (tLeft + tRight) / 2;

		build(iv * 2, tLeft, tMid);
		build(iv * 2 + 1, tMid, tRight);

		st[iv] = st[iv * 2] + st[iv * 2 + 1];
	}
}

long long query(int iv, int tLeft, int tRight, int left, int right) {
	if (right <= tLeft || tRight <= left) return 0;
	if (left <= tLeft && tRight <= right) return st[iv];

	int tMid = (tLeft + tRight) / 2;
	return query(iv * 2, tLeft, tMid, left, right) +
	       query(iv * 2 + 1, tMid, tRight, left, right);
}

void update(int iv, int tLeft, int tRight, int i, long long val) {
	if (tRight - tLeft == 1) {
		st[iv] = val;
	} else {
		int tMid = (tLeft + tRight) / 2;
		if (i < tMid) {
			update(iv * 2, tLeft, tMid, i, val);
		} else {
			update(iv * 2 + 1, tMid, tRight, i, val);
		}
		st[iv] = st[iv * 2] + st[iv * 2 + 1];
	}
} 

int main() {
	int q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];

	st[0] = 0;
	build(1, 0, n);

	while(q--) {
		int k, x, y;
		cin >> k >> x >> y;

		if (k == 2) {
			cout << query(1, 0, n, x - 1, y) << '\n';
		} else {
			update(1, 0, n, x - 1, y);
		}
	}

	return 0;
}