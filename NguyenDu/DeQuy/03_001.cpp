#include <iostream>
#include <vector>
using namespace std;

void dq(int d, const vector<int>& a, const int& n, vector<int>& b, int start) {
	if (d == 0) {
		for (const int& x : b) cout << a[x] << " ";
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) {
		b.push_back(i);

		dq(d - 1, a, n, b, i + 1);

		b.pop_back();
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> b;
	dq(k, a, n, b, 0);

	return 0;
}
