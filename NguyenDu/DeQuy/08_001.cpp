#include <iostream>
#include <vector>
using namespace std;

void dq(const vector<vector<bool>>& a, int startX, int startY, vector<vector<bool>>& b) {
	b[startX][startY] = true;

	// Do it in 4 cardinal directions
	int nextX, nextY;
	for (int i = 1; i <= 4; i++) {
		if      (i == 1) nextX = startX + 1, nextY = startY;
		else if (i == 2) nextX = startX - 1, nextY = startY;
		else if (i == 3) nextX = startX, nextY = startY + 1;
		else             nextX = startX, nextY = startY - 1;

		// Easy... easy...
		if (!a[nextX][nextY] && !b[nextX][nextY]) {
			// If a at nextX, nextY doesnt have rocks
			// and nextX, nextY wasnt traveled before by another dq recursion cycle above

			dq(a, nextX, nextY, b);
		}
	}
}

int main() {
	int n, m, y, x;
	cin >> n >> m >> y >> x;

	// x -= 1; y -= 1;

	vector<vector<bool>> a(m + 2, vector<bool>(n + 2, 1));
	// use a[x][y]
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;

			a[j][i] = x;
		}
	}
	
	/*
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			cout << a[j][i] << " ";
		}
		cout << "\n";
	}
	*/

	vector<vector<bool>> b(m + 2, vector<bool>(n + 2, 0));

	dq(a, x, y, b);

	long long c = 0;
	for (const vector<bool>& __b1 : b)
		for (const bool& __b2 : __b1)
			if (__b2) c++;

	cout << c;


	return 0;
}
