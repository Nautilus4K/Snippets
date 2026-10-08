#include <iostream>
#include <vector>
using namespace std;

void dq(long long n, vector<int>& rep) {
	if (n == 0) return;
	
	// cout << n % 2;
	rep.push_back((n % 2));
	dq(n / 2, rep);
}

int main() {
	long long n;
	cin >> n;
	
	vector<int> rep;
	dq(n, rep);

	for (int i = rep.size() - 1; i >= 0; i--) cout << rep[i];
	return 0;
}
