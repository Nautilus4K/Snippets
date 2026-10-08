#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<bool> st;
    string s;
    cin >> s;

    for (const char& x : s) {
        if (x == '(') st.push(true);
        else {
            if (!st.empty()) st.pop();
            else {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << (st.empty() ? "YES" : "NO");

    return 0;
}
