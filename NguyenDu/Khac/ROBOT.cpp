#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int x = 0, y = 0;

	for (const char& c : s) {
		switch (c) {
			case 'U':
				y++;
				break;
			case 'L':
				x--;
				break;
			case 'R':
				x++;
				break;
			case 'D':
				y--;
				break;
		}
	}

	cout << x << " " << y;

	return 0;
}
