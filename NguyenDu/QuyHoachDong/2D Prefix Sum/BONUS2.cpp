#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct square {
	int x1, y1, x2, y2;
	long long sum;
};

bool compareSquares(const square& s1, const square& s2) {
	return s1.sum > s2.sum;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<long long>> mcd(n + 1, vector<long long>(n + 1, 0));

	long long rs;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> rs;

			mcd[i][j] = rs + mcd[i - 1][j] + mcd[i][j - 1] - mcd[i - 1][j - 1];
		}
	}

	vector<square> squares;
	for (int x1 = 1; x1 <= n - k + 1; x1++) {
		int x2 = x1 + k - 1;

		for (int y1 = 1; y1 <= n - k + 1; y1++) {
			int y2 = y1 + k - 1;
			int sum = mcd[x2][y2] - mcd[x1 - 1][y2] - mcd[x2][y1 - 1] + mcd[x1 - 1][y1 - 1];

			square current;
			current.x1 = x1;
			current.x2 = x2;
			current.y1 = y1;
			current.y2 = y2;

			current.sum = sum;

			squares.push_back(current);
		}
	}

	sort(squares.begin(), squares.end(), compareSquares);

	

	return 0;
}