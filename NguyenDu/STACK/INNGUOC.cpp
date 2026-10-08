#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> a;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push(x);
    }

    while (!a.empty()) {
       cout << a.top() << '\n';
       a.pop();
    }

    return 0;
}
