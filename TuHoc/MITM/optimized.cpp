#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
vector<int> t(41);
vector<int> a(21), b(21);
vector<int> ta, tb; //sums
int n, x, ka, kb;

void dq1(ll& sum, int begin) {
	if (sum > x) return;
	ta.push_back(sum);
	for(int i = begin; i < ka; i++){
		sum += a[i];
		dq1(sum, i + 1);
		sum -= a[i];
	}
}

void dq2(ll& sum, int begin) {
	if (sum > x) return;
	tb.push_back(sum);
	for(int i = begin; i < kb; i++){
		sum += b[i];
		dq2(sum, i + 1);
		sum -= b[i];
	}
}

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> t[i];
	ka = n / 2;
	kb = n - ka; // mitm
	for (int i = 0; i < n; i++) {
		if (i < ka) a[i] = t[i];
		else b[i - ka] = t[i];
	}

	long long suma = 0, sumb = 0;
	dq1(suma, 0);
	dq2(sumb, 0);

	// binary search on b sums
	sort(tb.begin(), tb.end());
	int ways = 0;
	for (int w : ta) {
		int c = upper_bound(tb.begin(), tb.end(), x - w) - lower_bound(tb.begin(), tb.end(), x - w);
		ways += c;
	}

	cout << ways;

	return 0;
}