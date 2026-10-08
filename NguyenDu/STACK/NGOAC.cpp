#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<string> st;

    string curLayer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(curLayer);
            curLayer = "";
        } else if (s[i] == ')') {
            if (curLayer == "") {
                cout << "yes";
                return 0;
            }

            curLayer = st.top();
            st.pop();
        } else {
            curLayer += s[i];
        }
    }

    cout << (curLayer == "" ? "yes" : "no");

    return 0;
}
