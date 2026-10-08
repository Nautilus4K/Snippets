#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long maxArea = 0, l, t, r, b;
    int m, n;
    cin >> m >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // int x = proc(0, 0);
    // cout << "\n" << x << " " << maxArea;
    long long depth = -1;
    vector<int> depthsList;
    for (int i = 0; i < n; i++) {
        int cd = a[i];
        while (cd > depth) {
            // Create depthList entry
            depthsList.push_back(i);
            depth++;
        }

        while (cd < depth) {
            // cout << depthsList.back() << " " << i << "\n";
            // maxArea = max(maxArea, depth * (i - depthsList.back()));
            long long val = depth * (i - depthsList.back());
            if (val >= maxArea) {
                maxArea = val;

                l = 1;
                t = depthsList.back() + 1;
                r = depth;
                b = i;
            }

            depthsList.pop_back();
            depth--;
        }

        // i++;
    }
    maxArea = max(maxArea, depth * (n - depthsList.back()));

    for (int i = 0; i < n; i++) a[i] = m - a[i];

    depth = -1;
    depthsList = vector<int>();
    for (int i = 0; i < n; i++) {
        int cd = a[i];
        while (cd > depth) {
            // Create depthList entry
            depthsList.push_back(i);
            depth++;
        }

        while (cd < depth) {
            // cout << depthsList.back() << " " << i << "\n";
            // maxArea = max(maxArea, depth * (i - depthsList.back()));
            long long val = depth * (i - depthsList.back());
            if (val >= maxArea) {
                maxArea = val;

                l = m - depth + 1;
                t = depthsList.back() + 1;
                r = m;
                b = i;
            }

            depthsList.pop_back();
            depth--;
        }

        // i++;
    }
    maxArea = max(maxArea, depth * (n - depthsList.back()));

    // cout << depthsList.back() << " " << n << "\n";
    cout << maxArea << "\n" << l << " " << t << "\n" << r << " " << b;

    return 0;
}