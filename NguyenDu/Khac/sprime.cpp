#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1e6

bool isPrime(const long long& n) {
	if (n < 2) return false;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

bool isFullOfPrimes(const vector<int>& a) {
	// cout << "K";
	for (const int& x : a) {
		if (!isPrime(x)) {
			// cout << x << '\n';
			return false;
		}
	}

	return true;
}

int main() {
	string s;
	cin >> s;

	vector<int> nums;
	int currentNum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			if (currentNum != 0) {
				nums.push_back(currentNum);
				currentNum = 0;
			}
		} else {
			currentNum = (currentNum * 10) + int(s[i] - '0');
		}
	}
	if (currentNum != 0) nums.push_back(currentNum);
		
	int res = 0;
	if (nums.size() <= 20) {
		if (!isFullOfPrimes(nums)) {
			int k = 0;
			for (int i = 0; i < nums.size(); i++) {
				for (int j = k; j < i; j++) {
					if (__gcd(nums[i], nums[j]) != 1) {
						res = max(res, i - k);
					}
				}
			}
			cout << res;
		} else {
			cout << nums.size();
		}
	} else {
		cout << nums.size();
	}

	return 0;
}
