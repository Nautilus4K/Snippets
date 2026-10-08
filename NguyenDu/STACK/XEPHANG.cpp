#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long c = 0;
    stack<pair<int, int>> st; // number, repeats

    int x;
    while (n--) {
        cin >> x;

        int count_ = 1; // Dups

        while (!st.empty() && st.top().first < x) {
            c += st.top().second;
            cout << st.top().first << '\n';
            st.pop();
        }

        if (!st.empty() && st.top().first == x) {
            c += st.top().second;
            count_ += st.top().second;
            // cout << st.top().first << '\n';
            st.pop();
        }

        if (!st.empty()) {
            c++;
        }

        st.push({x, count_});
    }

    cout << c;

    return 0;
}
