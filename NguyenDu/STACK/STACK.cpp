#include <iostream>
#include <stack>
using namespace std;

int main() {
    int q;
    cin >> q;

    stack<long long> st;

    while(q--) {
        int p;
        cin >> p;

        if (p == 1) {
            long long x;
            cin >> x;

            st.push(x);
        } else if (p == 2) {
            if (!st.empty()) st.pop();
        } else {
            if (!st.empty()) cout << st.top() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}
