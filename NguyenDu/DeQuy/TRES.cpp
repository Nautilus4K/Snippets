#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int m, n;
vector<int> p;
vector<set<int>> a;
long long lowestCost = LLONG_MAX;

bool check(const vector<long long>& lsx) {
	// vvvvv
	cout << "check(): ";
	for (const long long& x : lsx) cout << x << " ";
	cout << '\n';
	for (const set<int>& s : a) {
		// each guy
		cout << "D: ";
		int likes = 0;
		for (const int& x : s) {
			auto it = lower_bound(lsx.begin(), lsx.end(), x);
			if (it == lsx.end()) continue;
				
			if (*it == x - 1) {
				cout << *it << ' ';
				likes++;
			} else {
				cout << "(" << x - 1 << ")" << " ";
			}
		}
		cout << '\n';

		if (likes != 2) return false;
	}

	return true;
}

void dq(int start, long long& cost, vector<long long>& lsx) {
	if (check(lsx)) lowestCost = min(cost, lowestCost);

	for (int i = start; i < m; i++) {
		cost += p[i];
		lsx.push_back(i);

		dq(i + 1, cost, lsx);
		
		lsx.pop_back();
		cost -= p[i];
	}
}

int main() {
	cin >> m >> n;

	// p = vector<int>(m);
	p.reserve(m);
	
	vector<int> ps(m);
	for (int i = 0; i < m; i++) cin >> ps[i];

	p = ps;

	cin.ignore();

	a = vector<set<int>>(n);
	for (int i = 0; i < n; i++) {
		string s;
		// cin.ignore();
		getline(cin, s);

		// Process the input string.
		int currentNumber = 0;
		for (const char& x : s) {
			if (isdigit(x)) currentNumber = currentNumber * 10 + int(x - '0');
			else {
				a[i].insert(currentNumber);
				currentNumber = 0;
			}
		}
		if (currentNumber > 0) a[i].insert(currentNumber);
	}
	
	/*
	vector<int> likes(m, 0);
	for (const set<int>& s : a) {
		for (const int& x : s) likes[x - 1]++; 
	}

	for (int i = 0; i < m; i++) {
		if (likes[i] == 2) {
			p.push_back(ps[i]);
			cout << ps[i] << '\n';
		}
	}

	cout << '\n';
	*/
	
	
	for (const set<int>& s : a) {
		for (const int& x : s) cout << x << " ";
		cout << '\n';
	}
	
	
	long long cost;
	vector<long long> lsx;
	dq(0, cost, lsx);

	cout << lowestCost;

	return 0;
}
