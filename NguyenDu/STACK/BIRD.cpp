#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> atw(n);
    for (int i = 0; i < n; i++) atw[i] = {a[i], i};

    sort(atw.begin(), atw.end());

    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) st.push(atw[i]);

    long long c = 0;
    set<int> killedIndexes;
    while (!st.empty()) {
        // kill st.top().
        int mid = st.top().first;
        int left = st.top().second - 1, right = st.top().second + 1;

        while (killedIndexes.count(left)) left--;
        while (killedIndexes.count(right)) right++;

        if (left < 0) left = 0;
        else left = a[left];

        if (right >= n) right = 0;
        else right = a[right];

        c += (left + mid + right);
        killedIndexes.insert(st.top().second);
        st.pop();
    }

    cout << c;

    return 0;
}
