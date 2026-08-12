#include <iostream>
using namespace std;

int dem(int a[], int n, int i) {
	if (i == n - 1) return (a[i] > 0);
	
	if (a[i] > 0) return 1 + dem(a, n, i + 1);
	else return dem(a, n, i + 1);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << dem(a, n, 0);
	return 0;
}
