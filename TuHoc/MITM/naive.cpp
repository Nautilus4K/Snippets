// backtracking
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<int> t(41);
int n, x;

void dq(ll& sum, ll& ways, int begin) {
	if(sum == x) ways++;
	for(int i = begin; i < n; i++){
		sum += t[i];
		dq(sum, ways, i + 1);
		sum -= t[i];
	}
}

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> t[i];

	// backtrack
	ll ways = 0, sum = 0;
	dq(sum, ways, 0);
	cout << ways;

	return 0;
}