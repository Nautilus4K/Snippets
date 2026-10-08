#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;

	set<int> a;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.insert(x);
	}

	int q;
	cin >> q;

	for (int __q = 0; __q < q; __q++) {
		int p, x;
		cin >> p;

		if (p != 5) cin >> x;

		if (p == 1) {
			a.insert(x);
		} else if (p == 2) {
			a.erase(x);
		} else if (p == 3) {
            set<int>::iterator it = a.upper_bound(x);
            if (it == a.end()) cout << "No\n";
            else cout << *it << '\n';
		} else if (p == 4) {
            set<int>::iterator it = a.lower_bound(x);
            if (it == a.begin()) cout << "No\n";
            else {
                it--;
                cout << *it << '\n';
            }
		} else if (p == 5) {
		    // for (const int& r : a) cout << r << " ";
		    // cout << '\n';
            cout << *a.begin() << " " << *a.rbegin() << '\n';
		}
	}

	return 0;
}
