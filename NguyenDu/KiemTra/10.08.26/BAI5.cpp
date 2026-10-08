#include <iostream>
#include <vector>
using namespace std;

bool validate(const string& s, const vector<bool>& skipped) {
	int prevzerocount = -1;
	int zerocount = 0;
	for (int i = 0; i < s.size(); i++) {
		if (skipped[i]) continue;

		if (s[i] == '0') zerocount++;
		else {
			// s[i] == '1'
			if (prevzerocount != -1 && zerocount != prevzerocount) {
				return false;
			}

			prevzerocount = zerocount;
			zerocount = 0;
		}
	}

	return (prevzerocount == zerocount);
}

void dq() {
}

int main() {
	freopen("BAI5.INP", "r", stdin);
	freopen("BAI5.OUT", "w", stdout);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<bool> skipped(n, false);
	vector<int> locations;
	locations.reserve(n);

	for (int i = 0; i < n; i++) if (s[i] == '1') locations.push_back(i);
	cout << validate(s, skipped);

	return 0;
}
