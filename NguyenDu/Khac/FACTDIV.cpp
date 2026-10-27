#include <iostream>
using namespace std;

long long disv = 1e9 + 7;

long long gt(long long n) {
	if (n == 0) return 1;

	return ((gt(n - 1) % disv) * n) % disv;
}

int main() {
	long long n, m;
	cin >> n >> m;

	// nghich dao modulo
	long long mx = 0;
	while ((mx * m) % disv != 1) mx++;
	cout << mx << '\n';

	cout << (gt(n) * mx) % disv;

	return 0;
}