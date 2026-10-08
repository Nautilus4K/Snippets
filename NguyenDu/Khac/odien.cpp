#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end(), greater<int>());

	int res = 1;
	int curIdx = 0;

	while (res < m && curIdx < a.size()) {
		res -= 1;
		res += a[curIdx];

		curIdx++;
	}

	cout << (curIdx >= a.size() ? -1 : curIdx);

	return 0;
}
