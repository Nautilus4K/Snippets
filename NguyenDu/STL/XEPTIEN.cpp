#include <iostream>
#include <algorithm>
using namespace std;

bool cmpfunc(const pair<int, int>& x, const pair<int, int>& y) {
	if (x.second == y.second) return x.first > y.first;
	return x.second < y.second;
}

int main() {
	int n;
	cin >> n;
	
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}
	
	sort(a, a + n, cmpfunc);
	for (int i = 0; i < n; i++) cout << a[i].first << " " << a[i].second << "\n";
}