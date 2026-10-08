#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	int n, k, m;
	cin >> n >> k >> m;

	queue<pair<int, int>> a;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push({x, i});
	}

	map<int, int> r;

	while(m--) {
		if (a.size() == 0) continue;

		pair<int, int> w = {a.front().first, a.front().second};
		a.pop();

		r[w.second]++;

		if (w.first > k) a.push(w);
	}
	
	for (int i = 0; i < n; i++) cout << r[i] << " ";

	return 0;
}
