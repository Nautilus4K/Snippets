#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int m, n, q;
	cin >> m >> n >> q;
	
	// m < n
	bool swapping = false;
	if (m > n) {
		swapping = true;
		swap(m, n);
	}
	
	vector<vector<bool>> k(m, vector<bool>(n + 1, false));
	
	for (int __q = 0; __q < q; __q++) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		if (swapping) {
			swap(x, y);
			swap(u, v);
		}
		
		for (int i = x; i <= u; i++) {
			k[i - 1][y - 1] = !k[i - 1][y - 1];
			k[i - 1][v] = !k[i - 1][v];
		}
	}
	
	long long c = 0;
	for (const vector<bool>& kn : k) {
		bool adding = false;
		for (const bool& kn2 : kn) {
			if (kn2) {
				adding = !adding;
			}
			
			if (adding) c++;
		}
		
//		cout << '\n';
	}
	
	cout << c;
	
	return 0;
}