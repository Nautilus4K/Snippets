#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team {
	int a, b, c;
};

bool xXx_c0mp4rat0r_xXx(const Team& a, const Team& b) {
	return a.a < b.a;
}

int main() {
	int n;
	cin >> n;

	vector<Team> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].a >> a[i].b >> a[i].c;
	
	sort(a.begin(), a.end(), xXx_c0mp4rat0r_xXx);

	vector<int> dp(n);
	//dp.reserve(n);
	int val = 0;
	
	for (int i = 0; i < n; i++) {
		//int cval = a[i].c;
		//ehhhh whatever
		dp[i] = a[i].c; //c as replacement for 1
		for (int j = 0; j < i; j++) {
			if (a[i].a > a[j].b || a[i].b < a[j].a) {
				dp[i] = max(dp[i], dp[j] + a[i].c);
				//cval += a[j].c;
				//so...
			}
		}

		//val = max(val, cval);
		val = max(val, dp[i]);
	}
	
	cout << val;

	return 0;
}
