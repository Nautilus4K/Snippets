#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<long long> st;

    long long klht = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(klht);
            klht = 0;
        } else if (s[i] == ')') {
            if (i < s.size() - 1 && isdigit(s[i + 1])) {
                // There is number at s[i + 1]
                klht = st.top() + (klht * int(s[i + 1] - '0'));
                st.pop();

                i++; // Skip the number at i + 1
            } else {
                klht = st.top() + klht;
                st.pop();
            }
        } else {
            // It's not either '(' or ')' or numbers, its C, H, O
            long long kl = 0;
            switch (s[i]) {
                case 'C':
                    kl = 12;
                    break;
                case 'H':
                    kl = 1;
                    break;
                case 'O':
                    kl = 16;
                    break;
            }

            if (i < s.size() - 1 && isdigit(s[i + 1])) {
                klht += kl * int(s[i + 1] - '0');
            } else {
                klht += kl;
            }
        }
    }

    cout << klht;

    return 0;
}
