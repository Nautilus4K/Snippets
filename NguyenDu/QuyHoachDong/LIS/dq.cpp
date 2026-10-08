#include <iostream>
#include <vector>
using namespace std;

vector<int> saved(1e6 + 1, -1);

int dq(const vector<int>& a, int idx) {
	if (saved[idx] != -1) return saved[idx];

	if (idx == 0) return 1;
	int ans = 1;

	for (int i = 0; i < idx; i++) {
		if (a[i] < a[idx]) {
			ans = max(ans, dq(a, i) + 1);
		}
	}
	
	saved[idx] = ans;
	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = 1;
	for (int i = 0; i < n; i++) ans = max(ans, dq(a, i));
	cout << ans;

	return 0;
}
