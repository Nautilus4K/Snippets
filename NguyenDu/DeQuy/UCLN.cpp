#include <iostream>
using namespace std;

long long ucln(long long a, long long b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;

	return ucln(a % b, b);
}

int main() {
	long long a, b;
	cin >> a >> b;
	cout << ucln(a, b);

	return 0;
}
