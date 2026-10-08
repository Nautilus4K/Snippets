#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	pair<int, int> a[n];
	int cl[int(1e4)];
	
	memset(cl, 0, sizeof(cl));
	
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		
		cl[abs(a[i].first - a[i].second)]++;
	}
	
	int biggestDiffIdx = 0;
	for (int i = 0; i < 1e4; i++) {
		if (cl[biggestDiffIdx] < cl[i]) {
			biggestDiffIdx = i;
		}
	}
	
	cout << biggestDiffIdx << "\n";
	
	for (int i = 0; i < n; i++) {
		if (abs(a[i].first - a[i].second) == biggestDiffIdx) {
			cout << a[i].first << " " << a[i].second << "\n";
		}
	}
	
	return 0;
}