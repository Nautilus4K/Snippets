#include <iostream>
using namespace std;

int dem(long long n) {
	if (n == 0) return 0;
	else return 1 + dem(n / 10);
}

int main() {
	long long n;
	cin >> n;

	cout << dem(n);

	return 0;
}
