#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmpfunc(const pair<string, pair<int, int>>& x, const pair<string, pair<int, int>>& y) {
	return x.second.first + x.second.second > y.second.first + y.second.second;
}

int main() {
	int n;
	cin >> n;
	
	pair<string, pair<int, int>> a[n];
	string inv[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second.first >> a[i].second.second;
		
		inv[i] = a[i].first;
	}
	
	sort(a, a + n, cmpfunc);
	for (int i = 0; i < n; i++) {
		// int th = 1;
		for (int j = 0; j < n; j++) {
			// if (j > 0) if (a[j].second.first + a[j].second.second != a[j - 1].second.first + a[j - 1].second.second) th = j + 1;
			
			if (a[j].first == inv[i]) {
				int count = 1;
				for (int k = j; k >= 0; k--) 
					if (a[k].second.first + a[k].second.second > a[j].second.first + a[j].second.second) count++;
				
				cout << inv[i] << " " << count << "\n";
			}
		}
	}
	
	return 0;
}