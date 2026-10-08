#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmpfunc(const pair<int, int>& a, const pair<int, int>& b){
    // Sorting descending, so that B1 >= B2.
    // Because if B1 <= B2, a smaller pad will be on top of the stack, and the bigger ones wont be able to touch it.
    // Also because only if we do this, then would the -B below work since we need B1 >= B2 already.
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), cmpfunc);

    // cout << maxSize;
    // I need to find A increasing and B decreasing, respectively.
    // Kinda like LIS, but here, because B is decreasing, I have to make B go up
    // So instead of working with B, I am working with -B.
    // Basically, I need:
    // A1 <= A2
    // B1 >= B2
    // So with the sort, and I don't need to care about indexes, A1 <= A2 is always true.
    // Just need to find B1 >= B2
    vector<int> l;
    for (int i = 0; i < n; i++) {
        // Find the place I need to replace
        auto it = upper_bound(l.begin(), l.end(), -a[i].second); // So... upper_bound for >=, and lower_bound for > ???

        if (it == l.end()) l.push_back(-a[i].second);
        else *it = -a[i].second; // Iterator works like a pointer here. Yeah weird as fuck.
    }

    cout << l.size();

    return 0;
}