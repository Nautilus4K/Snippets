#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    // dp this shit yeah
    stack<int> st;
    vector<int> pre(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= h[i]) {
            st.pop();
        }

        st.push(h[i]);

        pre[i] = st.size();

        // cout << i << " " << h[i] << " " << st.size() << '\n';
    }

    int x;
    for (int __q = 1; __q <= q; __q++) {
        cin >> x;
        cout << pre[x - 1] - 1 << '\n';
    }

    return 0;
}
