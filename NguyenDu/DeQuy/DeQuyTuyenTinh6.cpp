#include <iostream>
using namespace std;

int stb(int n) {
	if (n == 1) return 1;
	
	return (stb(n - 1) * n + n) / n;
}

int main() {
	int n;
	cin >> n;

	return 0;
}
