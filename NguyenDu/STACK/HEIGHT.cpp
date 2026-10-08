#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int q;
    cin >> q;

    for (int __q = 1; __q <= q; __q++) {
        int n;
        cin >> n;

        vector<int> h(n);
        stack<pair<int, int>> st;
        vector<int> pre(1), linked(n);

        int rindex = 0;
        for (int i = 0; i < n; i++) {
            cin >> h[i];

            int c = 0;

            while (!st.empty() && st.top().first < h[i]) {
                st.pop();
            }

            if (!st.empty() && st.top().first == h[i]) {
                c++;
                st.pop();

                linked[i] = rindex;
            } else {
                rindex++;
                linked[i] = rindex;
                pre.push_back(0);
            }

            st.push({h[i], c});

            // cout << rindex << " " << h[i] << " " << c << '\n';

            pre[rindex] = c;
        }

        for (int i = 0; i < n; i++) cout << pre[linked[i]] << ' ';
        cout << '\n';
    }

    return 0;
}
