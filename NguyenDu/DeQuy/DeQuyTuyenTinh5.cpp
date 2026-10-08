#include <iostream>
using namespace std;

int vtmax(int a[], int n) {
	if (n < 1) return n;

	// return max(vtmax(a, n - 1), a[n]);
	int k = vtmax(a, n - 1);
	if (a[n] < a[k]) return k;
	else return n;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << a[vtmax(a, n - 1)];

	return 0;
}
