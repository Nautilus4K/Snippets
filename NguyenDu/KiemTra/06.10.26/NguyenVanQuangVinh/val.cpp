#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("val.inp", "r", stdin);
	freopen("val.out", "w", stdout);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	if (k == 1) {
		int x = a[0];
		int maxl = 1;

		int start = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] != x) {
				maxl = max(maxl, i - start);
				start = i;
				x = a[i];
			}
		}

		maxl = max(maxl, n - start);

		cout << maxl;
	} else {
		// k == 2
		int x = a[0], y = -1;

		int maxl = 2;

		int startx = 0;
		int starty = -1;
		int start = 0;
		for (int i = 1; i < n; i++) {
			// cout << "> " << a[i] << ":";
			if (a[i] != x && a[i] != y) {
				if (y == -1) {
					// cout << "SET Y";
					// y not set
					y = a[i];
					starty = i;
				} else {
					// cout << ">";
					// x and y set
					if (a[i - 1] == x) {
						// cout << "A";
						// starty = i;
						// start = startx;
						int j;
						for (j = i - 1; j >= 0; j--) {
							if (a[j] != a[i - 1]) break;
						}
						start = j + 1;

						y = a[i];

						// cout << " NEW Y " << y << " / NEW START " << start;
					} else {
						// it must be y
						// cout << "B";
						// startx = i;
						// start = starty;
						
						int j;
						for (j = i - 1; j >= 0; j--) {
							if (a[j] != a[i - 1]) break;
						}
						start = j + 1;

						x = a[i];

						// cout << " NEW X " << x << " / NEW START " << start;
					}
					// cout << maxl << " " << x << " " << y << " " << startx << " " << starty << " " << start << '\n';
				}
			}
			// } else if (a[i] != x) {
			// 	start = starty;
			// } else if (a[i] != y) {
			// 	start = startx;
			// }

			maxl = max(maxl, i - start + 1);
			// cout << '\n';
		}

		// maxl = max(maxl, n - start);
		// cout << maxl << " " << x << " " << y << " " << startx << " " << starty << " " << start << '\n';

		cout << maxl;
	}

	return 0;
}