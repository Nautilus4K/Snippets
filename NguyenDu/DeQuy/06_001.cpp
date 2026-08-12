#include <iostream>
#include <vector>
// #include <math.h>
using namespace std;

void dqx(const vector<long long>& a, int start, vector<int>& built, int d, int& res) {
	for (int i = start; i < a.size(); i++) {
		if (built.size() == 0 || a[built.back()] < a[i]) {
			built.push_back(i);
			dqx(a, i + 1, built, d, res);
			built.pop_back();
		}
	}
	res = max(res, (int)built.size());
}

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> built;
	int res = 1;
	dqx(a, 0, built, 0, res);

	cout << res;

	return 0;
}
