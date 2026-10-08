#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 1e6
vector<bool> prime(MAX_N + 1, true);

void sieve() {
	prime[0] = prime[1] = false;

	for (int i = 2; i * i <= MAX_N; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= MAX_N; j += i) {
				prime[j] = false;
			}
		}
	}
}

bool checkAssym(int n) {
	int idx = 0;

	while (n > 0) {
		if (n % 2 == 0) idx++;
		else idx--;

		n /= 10;
	}

	return idx != 0;
}

int main() {
	sieve();

	int n;
	cin >> n;

	vector<int> a(n);

	int c = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (prime[a[i]]) {
			if (checkAssym(a[i])) c++;
		}
	}

	cout << c;

	return 0;
}
