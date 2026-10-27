#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());
	
	bool ok = false;
	for (int i = 0; i < n; i++) {
		
	}

	cout << (ok ? "YES" : "NO");

	return 0;
}