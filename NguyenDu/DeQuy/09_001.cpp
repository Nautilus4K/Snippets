#include <iostream>
#include <vector>
using namespace std;

void dq(const vector<vector<bool>>& a, int startX, int startY, const int& dx, const int& dy, vector<vector<bool>>& b, bool& found) {
	if (startX == dx && startY == dy) {
		found = true;
		return;
	}

	b[startX][startY] = true;

	// Do it in 4 cardinal directions
	int nextX, nextY;
	for (int i = 1; i <= 4; i++) {
		if      (i == 1) nextX = startX + 1, nextY = startY;
		else if (i == 2) nextX = startX - 1, nextY = startY;
		else if (i == 3) nextX = startX, nextY = startY + 1;
		else             nextX = startX, nextY = startY - 1;

		// Alright alright chill down
		if (!a[nextX][nextY] && !b[nextX][nextY]) {
			dq(a, nextX, nextY, dx, dy, b, found);
			if (found) return;
		}
	}
}

int main() {
	int n, sy, sx, dy, dx;
	cin >> n >> sy >> sx >> dy >> dx;

	vector<vector<bool>> a(n + 2, vector<bool>(n + 2, 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;

			a[j][i] = x;
		}
	}

	// use a[x][y]...
	vector<vector<bool>> b(n + 2, vector<bool>(n + 2, 0));
	bool found = false;

	dq(a, sx, sy, dx, dy, b, found);

	cout << (found ? "YES" : "NO");


	return 0;
}
