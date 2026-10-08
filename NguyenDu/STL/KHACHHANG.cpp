#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<vector<int>::iterator> marked;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;

        vector<int>::iterator it = lower_bound(a.begin(), a.end(), x);
        while (it == a.end() || marked.count(it)) it--;

        if (*it < x) {
            it = a.begin();
            while (marked.count(it)) it++;
        }

        cout << int(it - a.begin()) + 1 << " ";
        // cout << *it << " ";
        marked.insert(it);
    }

    return 0;
}
