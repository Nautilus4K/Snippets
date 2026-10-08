#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;
int n;
vector<int> a(1e4); // cho chac an

// ktra. ko bt lam lis T_T
bool check(vector<int> x) {
	int last1 = 1, last2 = 1;

	for (int i = 0; i < x.size(); i++) {
		if (x[i] > last1) last1 = x[i];
		else if (x[i] > last2) last2 = x[i];
		else return false;
	}

	return true;
}

void sub1(int idx, vector<int>& x, int& c) {
	if (x.size() >= 2) {
		if (check(x)) {
			// for (int xa : x) cout << xa << " ";
			// cout << '\n';
			c++;
		}
		else {
			return;
		}
	}

	for (int i = idx; i < n; i++) {
		x.push_back(a[i]);
		sub1(i + 1, x, c);
		x.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("INC.INP", "r", stdin);
	freopen("INC.OUT", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	// du sao cung ko lam dc sub 234, gom dc nhieu thi gom
	if (true) {
		// sub 1
		vector<int> x;
		int c = 0;
		sub1(0, x, c);
		cout << c;
	}

	return 0;
}