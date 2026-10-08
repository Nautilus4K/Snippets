#include <iostream>
using namespace std;

long long tong(long long n) {
	if (n == 0) return 0;
	else return (n % 10) + tong(n / 10);
}

int main() {
	long long n;
	cin >> n;

	cout << tong(n);

	return 0;
}
