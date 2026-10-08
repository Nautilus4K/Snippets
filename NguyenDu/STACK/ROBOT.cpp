#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stack<char> st;
    for (const char& x : s) if (x != ' ') st.push(x);

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}
