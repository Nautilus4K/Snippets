#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // sort(a.begin(), a.end());
    unordered_map<int, int> repetitions;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // cout << i + j << " : " << repetitions[i + j] << " -> " << repetitions[i + j] + 1 << '\n';
            repetitions[a[i] + a[j]]++;
        }
    }

    long long c = 0;
    for (int i = 0; i < n; i++) {
        // cout << i << " " << repetitions[a[i]] << '\n';
        c += repetitions[a[i]];
    }

    cout << c;


    return 0;
}
