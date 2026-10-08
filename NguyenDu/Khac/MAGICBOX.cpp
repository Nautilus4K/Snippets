#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> left(m);
    for (int i = 0; i < m; i++) cin >> left[i];

    vector<int> bottom(n);
    for (int i = 0; i < n; i++) cin >> bottom[i];

    vector<int> right(m);
    for (int i = 0; i < m; i++) cin >> right[i];

    vector<int> top(n);
    for (int i = 0; i < n; i++) cin >> top[i];

    vector<vector<vector<int>>> possibilites;
    
    for (int i = 0; i < m; i++) {
        // Let's work with left first
        // There are 2 ways. The light could end up on the right side, or end up on the top side
        int in = i + 1, out = left[i];

        vector<vector<vector<int>>> currentPossibilities;
        
    }
}