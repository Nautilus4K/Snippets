#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> a(n + 1, vector<int>(0));
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		
		if (x == y) continue;
		
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++) {
		for (const int& x : a[i]) {
			cout << x << " ";
		}
		cout << "0\n";
	}
	
	return 0;
}