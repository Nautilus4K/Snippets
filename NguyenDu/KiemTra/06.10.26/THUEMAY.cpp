#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// vector<int> a(1001), b(1001), c(1001);
int n;

struct tg {
	int a, b, c;
};

vector<tg> w(1001);
// vector<tg> ht;
long long giai() {
	vector<long long> dp(n);
	for (int i = 0; i < n; i++) dp[i] = w[i].c;

	long long res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (!(max(w[i].a, w[j].a) < min(w[i].b, w[j].b))) {
				dp[i] = max(dp[i], dp[j] + w[i].c);
			}
		}

		res = max(res, dp[i]);
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// freopen("THUEMAY.INP", "r", stdin);
	// freopen("THUEMAY.OUT", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i].a >> w[i].b >> w[i].c;
	// sort(b.begin(), b.end());
	sort(w.begin(), w.begin() + n, [](const tg& a, const tg& b){
		return a.b < b.b;
	});

	cout << giai();

	return 0;
}