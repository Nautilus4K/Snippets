#include <bits/stdc++.h>
using namespace std;

map<string, long long> length;

string encode(long long a, long long b) {
	string as = "", bs = "";

	while (a > 0) {
		as += char(a % 10);
		a /= 10;
	}

	while (b > 0) {
		bs += char(b % 10);
		b /= 10;
	}

	return as + "," + bs;
}

void save(const long long& a, const long long& b, const long long& w) {
	if (a < b) length[encode(a, b)] = w;
	else length[encode(b, a)] = w;
}

long long getLength(const long long& a, const long long& b) {
	if (a < b) return length[encode(a, b)];
	else return length[encode(b, a)];
}

// s is start
// t is destination
void dq(map<long long, vector<long long>>& mapping, long long s, long long t, vector<long long>& plan, set<long long>& traveled, bool& found) {
	if (s == t) {
		// FOUND
		found = true;
		return;

	}

	for (const long long& x : mapping[s]) {
		if (!traveled.count(x)) {
			// Try this out?
			traveled.insert(x);
			plan.push_back(x);

			dq(mapping, x, t, plan, traveled, found);
			if (found) return;

			traveled.erase(x);
			plan.pop_back();
		}
	}
}

int main() {
	freopen("TRAVEL.INP", "r", stdin);
	// freopen("TRAVEL.OUT", "w", stdout);

	int n, q;
	cin >> n >> q;

	// cout << "Yo\n";

	// vector<long long> u(n - 1), v(n - 1), w(n - 1);
	map<long long, vector<long long>> mapping;
	for (int i = 0; i < n - 1; i++) {
		// Alright alright
		long long u, v, w;
		cin >> u >> v >> w;
		// cout << u << " " << v << " " << w << '\n';

		// u_i HAVE TO <= v_i
		if (u > v) swap(u, v);
		if (mapping.count(u)) {
			mapping[u].push_back(v); // SWAPPING AHHH
		} else {
			mapping[u] = { v };
		}
		
		if (mapping.count(v)) {
			mapping[v].push_back(u);
		} else {
			mapping[v] = { u };
		}

		save(u, v, w);
	}

	// Good.
	// Now.
	/*
	for (int __q = 0; __q < q; __q++) {
		long long s, t;
		cin >> s >> t;
		
		vector<long long> plan;
		set<long long> traveled;
		bool found = false;
		dq(mapping, s, t, plan, traveled, found);
		
		long long cost = 0;
		for (int i = 0; i < plan.size() - 1; i++) {
			cost += getLength(plan[i], plan[i + 1]);
			cout << plan[i] << " -> " << plan[i + 1[ << '\n';
		}

		cout << cost + 1 << '\n'; // +1 for dest
	}*/
	
	for (int __q = 0; __q < q; __q++) {
		long long s, t;
		cin >> s >> t;
		// cout << s << " " << t << "\n";

		// cout << s << " " << t << '\n';

		// s is start
		// t is destination
		long long cost = 0;
		long long currentCity = s;
		set<long long> traveled;
		while (currentCity != t) {
			cost++;
			traveled.insert(currentCity);
			
			// long long res;
			for (const long long& x : mapping[currentCity]) {
				if (!traveled.count(x)) {
					cost += getLength(currentCity, x);
					currentCity = x;
					break;
				}
			}
		}

		cout << cost + 1 << '\n'; // +1 for the destination
	}
	return 0;
}
