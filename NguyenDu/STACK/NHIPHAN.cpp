#include <iostream>
#include <stack>
using namespace std;

int main() {
    long long x;
    while (cin >> x) {
        // Converting x into binary representation
        stack<bool> a;

        long long q = x;
        bool r = q % 2;

        while(q > 0) {
            r = q % 2;
            q /= 2;

            a.push(r);
        }

        while (!a.empty()) {
            cout << a.top();
            a.pop();
        }

        cout << '\n';
    }

    return 0;
}
