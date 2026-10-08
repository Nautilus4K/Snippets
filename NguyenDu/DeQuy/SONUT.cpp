#include <iostream>
using namespace std;

long long tcs(long long n) {
	long long t = 0;
	while (n > 0) {
		t += n % 10;
		n /= 10;
	}

	return t;
}

long long sonut(long long n) {
	long long t = tcs(n);
	if (t > 9) return sonut(t);
	else return t;
}

int main() {
	long long n;
	cin >> n;
	cout << sonut(n);
	return 0;
}
