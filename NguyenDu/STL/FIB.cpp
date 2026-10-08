#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> fib(93);
    set<long long> fibs;
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < fib.size(); i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        fibs.insert(fib[i]);
    }

    long long fibMin = LLONG_MAX, fibMax = -LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (fibs.count(a[i])) {
            fibMin = min(fibMin, a[i]);
            fibMax = max(fibMax, a[i]);
        }
    }

    cout << fibMin << "," << fibMax;

    return 0;
}
