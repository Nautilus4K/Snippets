#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

long long dcount(long long n, long long x, long long y) {
	return (y / n) - ((x - 1) / n);
}

int main() {
	long long a, b, x, y;
	cin >> a >> b >> x >> y;	

	cout << abs(dcount((a * b) / __gcd(a, b) , x, y) - dcount(a, x, y));

	return 0;
}
