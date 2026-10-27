#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1e5 + 7
int n;
vector<int> st(4 * MAX_N);

// void build(int iv, int tLeft, int tRight) {
// 	if (tRight - tLeft == 1) {
// 		st[iv] = a[tLeft];
// 	} else {
// 		int tMid = (tLeft + tRight) / 2;

// 		build(iv * 2, tLeft, tMid);
// 		build(iv * 2 + 1, tMid, tRight);

// 		st[iv] = max(st[iv * 2], st[iv * 2 + 1]);
// 	}
// }

long long query(int iv, int tLeft, int tRight, int left, int right) {
	if (right <= tLeft || tRight <= left) return 0;
	if (left <= tLeft && tRight <= right) return st[iv];

	int tMid = (tLeft + tRight) / 2;
	return max(query(iv * 2, tLeft, tMid, left, right), query(iv * 2 + 1, tMid, tRight, left, right));
}

void update(int iv, int tLeft, int tRight, int i, int val) {
	if (tRight - tLeft == 1) {
		st[iv] = max(st[iv], val);
	} else {
		int tMid = (tLeft + tRight) / 2;
		if (i < tMid) {
			update(iv * 2, tLeft, tMid, i, val);
		} else {
			update(iv * 2 + 1, tMid, tRight, i, val);
		}
		st[iv] = max(st[iv * 2], st[iv * 2 + 1]);
	}
} 

int main() {
	cin >> n;
	vector<pair<int, int>> a(n); // val, pos

	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
		if (x.first != y.first) return x.first < y.first;
		else return x.second > y.second;
	});

	// st[0] = 0;
	// build(1, 0, n);
	for (int& x : st) x = 0;

	long long res = 0;
	for (int i = 0; i < n; i++) {
		long long best = query(1, 0, n, 0, a[i].second);
		long long current = best + 1;

		res = max(res, current);
		update(1, 0, n, a[i].second, current);
	}

	cout << res;

	return 0;
}