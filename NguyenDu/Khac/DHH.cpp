#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; long long s;
	cin >> n >> s;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long beauty = 1;
		long long currentSum = 0;

		for (int j = i; j < n; j++) {
			currentSum += a[j];

			if (currentSum > s) {
				currentSum = a[j];
				beauty++;
			}

			ans += beauty;
		}
	}

	cout << ans;

	return 0;
}
