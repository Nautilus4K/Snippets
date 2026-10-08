#include <climits>
#include <iostream>
#include <vector>
#include <set>
// #include <map>
using namespace std;

int n, m;
long long leastCostly = LLONG_MAX;
vector<vector<long long>> costMap;

void dq(const vector<vector<pair<int, long long>>>& cost, set<int>& traveled, int current_city, vector<int>& traveledDbg, long long& costAmount) {
	// for (const int& x : traveledDbg) cout << x << " ";
	// cout << '\n';

	if (traveled.size() == n) {
		// Traveled through all of them. We now check if the current city is connected to the first city
		bool ok = false;
		for (const pair<int, long long>& p : cost[current_city]) {
			if (p.first == 1) {
				ok = true;
				break;
			}
		}

		if (ok) {
			// calculate the cost
			// long long costAmount = 0;
			// cout << "Cost calculation: ";
			// for (int i = 0; i < traveledDbg.size() - 1; i++) {
			// 	costAmount += costMap[traveledDbg[i]][traveledDbg[i + 1]];
			// 	// cout << costMap[traveledDbg[i]][traveledDbg[i + 1]] << "(" << traveledDbg[i] << " -> " << traveledDbg[i + 1] << ") + ";
			// }
			costAmount += costMap[traveledDbg.back()][1];
			leastCostly = min(costAmount, leastCostly);
			costAmount -= costMap[traveledDbg.back()][1];
			// cout << "--> " << leastCostly << '\n';
		}

		return;
	}

	for (const pair<int, long long>& p : cost[current_city]) {
		if (!traveled.count(p.first)) {
			traveled.insert(p.first);
			costAmount += p.second;
	
			// cout << "+" << p.first << '\n';
			traveledDbg.push_back(p.first);

			dq(cost, traveled, p.first, traveledDbg, costAmount);

			// cout << "-" << p.first << '\n';
			traveledDbg.pop_back();

			traveled.erase(p.first);
			costAmount -= p.second;
		}
	}
}

int main() {	
	cin >> n >> m;
	
	vector<vector<pair<int, long long>>> cost(n + 1, vector<pair<int, long long>>(0));
	costMap = vector<vector<long long>>(n + 1, vector<long long>(n + 1));
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		cost[a].push_back({b, w});
		cost[b].push_back({a, w});

		costMap[a][b] = w;
		costMap[b][a] = w;
	}
	
	/*
	for (int i = 1; i <= n; i++) {
		for (const pair<int, long long>& x : cost[i]) {
			cout << i << " -> " << x.first << " : " << x.second << "\n";
		}
	}
	*/

	set<int> traveled;
	traveled.insert(1);
	long long costAmount = 0;
	vector<int> traveledDbg(1, 1);

	dq(cost, traveled, 1, traveledDbg, costAmount);

	cout << (leastCostly != LLONG_MAX ? leastCostly : -1);

	return 0;
}
