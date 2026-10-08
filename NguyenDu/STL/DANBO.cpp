#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);

	while(true) {
		bool deadEnd = true;
		int nr = q.size();
		// cout << nr << "\n";
		while (nr--) {
			/*
			if (nr == 0) {
				queue<int> q2 = q;
				while (!q2.empty()) {
					cout << q2.front() << " ";
					q2.pop();
				}
				cout << '\n';
			}*/

			// cout << nr << " .\n";
			int x = q.front();
			q.pop();

			if (x <= k || (x - k) % 2 != 0) {
				q.push(x);
			} else {
				// possible to divide
				deadEnd = false;

				// int num = ((x - k) / 2);
				q.push((x - k) / 2);
				q.push((x + k) / 2);
			}
		}

		// cout << q.size();

		if (deadEnd) break;
	}

	cout << q.size();

	return 0;
}
