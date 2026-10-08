#include <cstdio>
#include <iostream>
#include <vector>
// #include <set>
using namespace std;

/*
bool check(const int& n, const vector<int>& built) {
	for (int i = 1; i < n; i++) {
		if (abs(built[i] - built[i - 1]) <= 1) {
			// BEGONE
			return false;
		}
	}

	return true;
}*/

//bool valid(const int& i, )
bool checkpos(const int& x, const int& y, const vector<vector<bool>>& board, const int& n) {
	// Yehhh
	for (int i = x, j = y; i >= 1 && j >= 1; i--, j--) {
		if (board[i][j]) return false;
	}
	for (int i = x, j = y; i <= n && j <= n; i++, j++) {
		if (board[i][j]) return false;
	}
	for (int i = x, j = y; i <= n && j >= 1; i++, j--) {
		if (board[i][j]) return false;
	}
	for (int i = x, j = y; i >= 1 && j <= n; i--, j++) {
		if (board[i][j]) return false;
	}
	return true;
}

void dq(const int& n, int d, vector<int>& built, vector<bool>& taken, vector<vector<bool>>& board) {
	if (d == 0) {
		// cout << s << '\n';
		for (const int& x : built) cout << x << " ";
		cout << '\n';
		

		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!taken[i] && (built.size() > 0 ? checkpos(built.size() + 1, i, board, n) : true)) {
			built.push_back(i);
			taken[i] = true;
			// taken2.insert({i - (int)built.size(), 0});
			board[built.size()][i] = true;
			// cout << "> " << built.size() << ", " << i << '\n';;

			dq(n, d - 1, built, taken, board);
			
			// taken2.erase(i - built.size());
			board[built.size()][i] = false;
			taken[i] = false;
			built.pop_back();
		}
	}
}

int main() {
	// freopen("QUEEN.INP", "r", stdin);
	// freopen("QUEEN.OUT", "w", stdout);
	int n;
	cin >> n;

	vector<int> built;
	vector<bool> taken(n + 1);
	vector<vector<bool>> board(n + 1, vector<bool>(n + 1, false));

	dq(n, n, built, taken, board);

	return 0;
}
