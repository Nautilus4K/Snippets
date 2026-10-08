#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int n, m, kx, ky;
vector<pair<int, ll>> a(41);
vector<pair<int, ll>> x(21), y(21);
vector<pair<int, ll>> tx, ty;
void dq1(pair<int, ll>& sum, int begin) {
	if (sum.first > m) return;
	tx.push_back(sum);
	for(int i = begin; i < kx; i++){
		// sum += a[i];
		sum.first += x[i].first;
		sum.second += x[i].second;
		dq1(sum, i + 1);
		sum.first -= x[i].first;
		sum.second -= x[i].second;
	}
}

void dq2(pair<int, ll>& sum, int begin) {
	if (sum.first > m) return;
	ty.push_back(sum);
	for(int i = begin; i < ky; i++){
		sum.first += y[i].first;
		sum.second += y[i].second;
		dq2(sum, i + 1);
		sum.first -= y[i].first;
		sum.second -= y[i].second;
	}
}

int main() {
	cin >> n >> m;
	// w, v
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	kx = n / 2;
	ky = n - kx;

	for (int i = 0; i < n; i++) {
		if (i < kx) x[i] = a[i];
		else y[i - kx] = a[i];
	}

	pair<int, ll> sum1 = {0, 0}, sum2 = {0, 0};
	dq1(sum1, 0);
	dq2(sum2, 0);
	sort(ty.begin(), ty.end());

	vector<long long> sumVjmax(ty.size(), ty[0].second); // y
	vector<int> sumWj(ty.size());
	sumWj[0] = ty[0].first;
	for (int i = 1; i < ty.size(); i++) {
		sumVjmax[i] = max(sumVjmax[i - 1], ty[i].second);
		sumWj[i] = ty[i].first;
	}

	long long ans = 0;
	for (pair<int, long long> xa : tx) {
		// sumWj <= M - sumWi, sumVj max
		int j = upper_bound(sumWj.begin(), sumWj.end(), xa.second) - sumWj.begin() - 1;
		if (j >= 0)
			ans = max(ans, xa.second + sumVjmax[j]);
	}

	cout << ans;

	return 0;
}