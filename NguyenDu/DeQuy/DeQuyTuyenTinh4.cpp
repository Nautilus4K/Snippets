#include <iostream>
using namespace std;

long long tong(long long a[], int n) {
	if (n == 0) return a[0];

	if (a[n] % 2 == 0) return a[n] + tong(a, n - 1);
	else return tong(a, n - 1);
}

int main() {
	int n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << tong(a, n - 1);
	return 0;
}
