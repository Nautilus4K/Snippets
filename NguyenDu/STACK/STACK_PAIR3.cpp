#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<pair<int, pair<int, int>>> st;

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;

        st.push({a, {b, c}});
    }
}
