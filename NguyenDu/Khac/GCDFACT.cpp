#include <bits/stdc++.h>

using namespace std;

// long long fact(long long x) {
//     if (x == 0 || x == 1) return 1;
//     if (x == 2) return 2;

//     if (x > 12) return -1; // Too big

//     long long n = 1;
//     for (int i = 1; i <= x; i++) {
//         n *= i;

//         if (n > 1e9) {
//             // This is now way too big to contain. Also a_i will never exceed 1e9 so gcdA will never exceed 1e9 anyways
//             return -1;
//         }
//     }

//     return n;
// }

int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long minA = a[0];
        long long gcdA = a[0];
        for (int i = 1; i < n; i++) {
            minA = min(minA, a[i]);
            gcdA = __gcd(gcdA, a[i]);
        }

        cout << (minA == gcdA ? "YES\n" : "NO\n");
    }
}