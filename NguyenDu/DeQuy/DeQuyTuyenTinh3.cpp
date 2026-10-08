#include <iostream>
using namespace std;

long long gt(long long n) {
	if (n == 0) return 1;
	
	return n * gt(n - 1);
}

int main() {
	long long n;
	cin >> n;

	cout << gt(n);
}
