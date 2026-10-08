#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> a;
    int x;
    int f = -1;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (a.count(x - m - 1) || a.count(x + m + 1)) {
            f = i;

        }

        a.insert(x);
    }

    cout << f;

    return 0;
}
