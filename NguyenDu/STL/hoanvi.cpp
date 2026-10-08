#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int __q = 1; __q <= t; __q++) {
		string s;
		cin >> s;

		queue<int> chan, le;
		for (int i = 0; i < s.size(); i++) {
			int x = s[i];
			if (x % 2 == 0) chan.push(s[i] - '0');
			else            le.push(s[i] - '0');
		}

		queue<int> final;
		while (!chan.empty() || !le.empty()) {
			if (!chan.empty() && !le.empty()) {
				if (chan.front() <= le.front()) {
					final.push(chan.front());
					chan.pop();
				} else {
					final.push(le.front());
					le.pop();
				}
			} else if (!chan.empty()) {
				final.push(chan.front());
				chan.pop();
			} else if (!le.empty()) {
				final.push(le.front());
				le.pop();
			}
		}

		while (!final.empty()) {
			cout << final.front();
			final.pop();
		}
		cout << '\n';
	}

	return 0;
}
