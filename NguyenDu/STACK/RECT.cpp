#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main() {
    int m, n;
    cin >> m >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<pair<int, long long>> st; // depth, index

    int d = 0;
    long long biggest = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > d) {
            st.push({a[i], i});
            d = a[i];
        } else if (a[i] < d) {
            biggest = max(biggest, (i - (st.empty() ? 0 : st.top().second)) * d);

            while (!st.empty() && st.top().first > a[i]) st.pop();
            d = a[i];
        }

        // cout << i << " " << a[i] << " " << d << " {" << st.top().first << ", " << st.top().second << "}" << '\n';
    }

    // Reversed
    for (int i = 0; i < n; i++) a[i] = m - a[i];

    d = 0;
    stack<pair<int, long long>> st2;
    for (int i = 0; i < n; i++) {
        if (a[i] > d) {
            st2.push({a[i], i});
            d = a[i];
        } else if (a[i] < d) {
            biggest = max(biggest, (i - (st2.empty() ? 0 : st2.top().second)) * d);

            while (!st2.empty() && st2.top().first > a[i]) st2.pop();
            d = a[i];
        }

        // cout << i << " " << a[i] << " " << d << " {" << st2.top().first << ", " << st2.top().second << "}" << '\n';
    }

    cout << biggest;

    return 0;
}
