#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int proc(int r, int k) {
	// int r = n % k;
	// if (r == 0) return 0;
	// else return k - r;
	return (k - r) % k;
}

int main() {
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> pp;
	vector<int> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		// pp[a[i] % k]++;
	}
	
	long long count = 0;
	for (int i = 0; i < n; i++) {
		/*
		for (int j = i + 1; j < n; j++) {
			// cout << i << " " << j << " " << count << '\n';
			if ((a[i] + a[j]) % k == 0) count++;
		}*/
		int rem = (a[i] % k + k) % k;

		count += pp[proc(rem, k)];

		pp[rem]++;
	}

	cout << count;

	return 0;
}
