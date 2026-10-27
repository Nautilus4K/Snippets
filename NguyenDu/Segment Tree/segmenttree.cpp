#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 1e5 + 7
int n;

vector<long long> a(MAX_N + 1);
vector<long long> st(4 * MAX_N);

// iv: index of current vertex
// [tLeft, tRight) 2 boundaries of the segment
void build(int iv, int tLeft, int tRight) {
	// The structure of the array is gonna be that:
	// at index 1: sum of root
	// at indices 2 and 3: sums of two child vertices
	// at indices 4 to 7: sums of children of those two indices above.

	// An element at index i is represented by: [i, i + 1]
	if (tRight - tLeft == 1) {
		st[iv] = a[tLeft]; // tLeft is inclusive ('[')
	} else {
		int tMid = (tLeft + tRight) / 2;

		// With 1-indexing, the left child of a vertex at index i
		// is stored at index 2i, and the right one at index 2i + 1

		// We build the left child of the current vertex, with
		// its sum being ranges from current left bound to mid
		// careful not to touch other branches' children
		build(iv * 2, tLeft, tMid);

		// Same as above
		build(iv * 2 + 1, tMid, tRight);

		// Getting sum of 2 children
		st[iv] = st[iv * 2] + st[iv * 2 + 1];
	}
}

// [left, right): the user's desired sum range
long long query(int iv, int tLeft, int tRight, int left, int right) {
	// We are going down a branch with range being completely
	// out of focus. tLeft being too far right and tRight being
	// too far left
	if (right <= tLeft || tRight <= left) return 0;

	// This segment is completely nested inside the sum range 
	// the user wants
	if (left <= tLeft && tRight <= right) return st[iv];

	// We do binary looking ass action like building above.
	int tMid = (tLeft + tRight) / 2;
	return query(iv * 2, tLeft, tMid, left, right) +
	       query(iv * 2 + 1, tMid, tRight, left, right);
}

void update(int iv, int tLeft, int tRight, int i, long long val) {
	if (tRight - tLeft == 1) {
		// Just like in build(). If tRight - tLeft == 1, we know for
		// sure we are at the bottom-most layer of the tree.
		st[iv] = val;
	} else {
		int tMid = (tLeft + tRight) / 2;

		// Let's think for a moment.
		// Back in binary search, if the desired value we need
		// to find is smaller than the current mid, we would go
		// left (where the values are smaller), right?

		// Here its the same, we know that the position we are
		// finding has a smaller index than the current mid. So
		// we remove the right side, or go on the left side.
		// OR we could say we check out the left child!!
		if (i < tMid) {
			// Update the left child
			update(iv * 2, tLeft, tMid, i, val);
		} else {
			// The other child
			update(iv * 2 + 1, tMid, tRight, i, val);
		}

		// Update like back at build().
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