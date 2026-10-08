#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> a;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (!a.count(x - m - 1) && !a.count(x + m + 1)) {
            a.insert(x);
        } else {
            // cout << i << " " << x << " " << x - m << " " << x + m << "\n";
            cout << i;
            break;
        }
    }

    return 0;
}
