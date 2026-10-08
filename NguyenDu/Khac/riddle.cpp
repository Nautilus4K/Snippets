#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<long long>& a, int mid, int n, int k) {
	vector<long long> b;
	b.reserve(mid);
	for (int i = 0; i < mid; i++) b.push_back(a[i]);

	sort(b.begin(), b.end());
	int sum = 0;
	for (int i = 0; i < mid; i++) {
		if (b[i] > sum + 1) return false;
		sum += b[i];
		if (sum >= k) return true;
	}

	return false;
}

int main() {
	int t;
	cin >> t;
	for (int __q = 0; __q < t; __q++) {
		int n, k;
		cin >> n >> k;
		
		vector<long long> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		int low = 1, high = n, ans = -1;
		while (low <= high) {
        		int mid = low + (high - low) / 2;
	        	if (check(a, mid, n, k)) {
				ans = mid;
        			high = mid - 1; // Try finding a smaller prefix
			} else {
        			low = mid + 1;  // Increase prefix size
			}
		}
    
		cout << ans << "\n";
	}

	return 0;
}
