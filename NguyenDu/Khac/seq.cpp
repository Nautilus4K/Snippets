#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Continuous range
struct conrange {
	int start, end;

	int getDist() {
		return end - start + 1;
	}
};

int main() {
	int m, n;
	cin >> m >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		// if (a[i] == 0) a.pop_back();
	}
	sort(a.begin(), a.end());
	a.erase(a.begin());

	vector<conrange> j;
	int currentIdx = 0;
	
	conrange startRange;
	startRange.start = 0; startRange.end = 0;
	j.push_back(startRange);
	for (int i = 1; i < a.size(); i++) {
		if (a[i] - a[i - 1] > 1) {
			// AHHH DAMMIT
			conrange newRange;
			newRange.start = i;
			newRange.end = i;
			j.push_back(newRange);

			currentIdx++;
		} else {
			j[currentIdx].end = i;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < j.size() - 1; i++) {
		// Let's see... uhhh... w-which pair of conrange can be connected?
		if (a[j[i + 1].start] - a[j[i].end] == 2) {
			// Connectable
			ans = max(ans, j[i].getDist() + j[i + 1].getDist() + 1);
		}
	}

	cout << (ans == 0 ? 2 : ans); // cuz of 0

	return 0;
}
