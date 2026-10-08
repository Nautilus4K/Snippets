// #include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	// priority_queue<int, vector<int>, greater<int>> pr;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// int x;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());

	priority_queue<pair<int, pair<int, int>>> pr; // {sum, {index_a, index_b}}
	set<pair<int, int>> visited;

	// Pushing the maximum possible sum at the begin of a and b
	pr.push({a[0] + b[0], {0, 0}});
	visited.insert({0, 0});

	while (k-- && !pr.empty()) {
		auto current = pr.top();
		pr.pop();

		cout << current.first << " ";

		int i = current.second.first;
		int j = current.second.second;

		if (i + 1 < n && !visited.count({i + 1, j})) {
			pr.push({a[i + 1] + b[j], {i + 1, j}});
			visited.insert({i + 1, j});
		}

		if (j + 1 < n && !visited.count({i, j + 1})) {
			pr.push({a[i] + b[j + 1], {i, j + 1}});
			visited.insert({i, j + 1});
		}
	}
	
	return 0;
}
