#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1e6

vector<bool> prime(MAX_N + 1, true);

void sieve() {
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= MAX_N; i++) {
		if (prime[i])
			for (int j = i * i; j <= MAX_N; j += i) {
				prime[j] = false;
			}
	}
}

int main() {
	sieve();

	int n; size_t k;
	cin >> n >> k;

	vector<long long> a;
	a.reserve(n);

	long long x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (prime[x]) a.push_back(x);
	}

	if (k > a.size()) k = a.size();

	// for (const int& x : a) cout << prime[x] << " ";
	sort(a.begin(), a.end());
	long long kmaxSum = 0, kmaxProd = 1, kminSum = 0, kminProd = 1;
	for (int i = 0; i < k; i++) {
		kminSum += a[i];
		kminProd *= a[i];
	}
	
	//cout << k << " " << a.size() << " " << a.size() - k << '\n';
	long long cond = (a.size() - k);
	if (a.size() == k) cond = 0;
	for (int i = a.size() - 1; i >= cond; i--) {
		// cout << i << " >= " << (a.size() - k) << " --> " << (i >= (a.size() - k)) << '\n';
		kmaxSum += a[i];
		kmaxProd *= a[i];
	}

	cout << kminSum << " " << kmaxSum << " " << kminProd << " " << kmaxProd << '\n';

	return 0;
}
