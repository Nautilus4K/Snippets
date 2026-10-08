#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	
	long long g = __gcd(a, b);
	cout << a / g << " " << b / g;

	return 0;
}
