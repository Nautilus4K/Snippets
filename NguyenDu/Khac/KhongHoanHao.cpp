#include <iostream>
using namespace std;

long long tongHoanHao(long long n) {
	if (n < 1) return false;
	
	long long r = 1;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			r += i;

			if (i != (n / i)) r += n / i;
		}
	}

	return r;
}

int main() {
	long long a, b;
	cin >> a >> b;
	
	long long c = 0;
	for (long long i = a; i <= b; i++) {
		long long n = i;

		if (tongHoanHao(n) > n) c++;
	}

	cout << c;

	return 0;
}
