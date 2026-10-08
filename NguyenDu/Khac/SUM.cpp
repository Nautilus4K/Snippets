#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n), b(n), c(n), d(n);
    // Vcl
    unordered_map<long long, int> freqAB, freqCD;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        // freqAB[a[i] + b[i]]++;
        // freqCD[c[i] + d[i]]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            freqAB[a[i] + b[j]]++;
            freqCD[c[i] + d[j]]++;
        }
    }

    long long count = 0;
    for (const auto& x : freqAB) {
        // cout << x.first << " " << x.second << '\n';
        long long value = x.first;
        // Find -value in CD
        if (freqCD.count(-value)) count += (x.second * freqCD[-value]);
    }

    cout << count;

    return 0;
}