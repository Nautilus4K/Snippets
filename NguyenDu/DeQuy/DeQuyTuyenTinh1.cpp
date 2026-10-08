#include <iostream>
using namespace std;

long long s(long long n) {
	if (n == 1) return 1;
	else return n + s(n - 1);
}

int main() {
	long long n;
	cin >> n;

	// cout << s(n) << '\n' << (n * (n + 1)) / 2;
	cout << s(n);

	return 0;
}
