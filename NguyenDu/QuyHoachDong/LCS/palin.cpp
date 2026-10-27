#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	// cin >> m >> n;
	string s;
	cin >> s;
	int n = s.size();

	// expansion from center O(n^2) T and O(1) P
	int start = 0;
	int size = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 1; j++) {
			int low = i;
			int high = i + j;

			while (low >= 0 && high < n && s[low] == s[high]) {
				int clen = high - low + 1;
				if (size < clen) {
					size = clen;
					start = low;
				}

				low--;
				high++;
			}
		}
	}

	for (int i = start; i <= start + size; i++) cout << s[i];

	return 0;
}