#include <exception>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen("INTERLEAVE.INP", "r", stdin);
	freopen("INTERLEAVE.OUT", "w", stdout);

	string s1, s2, s3;

	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);

	// cout << s1 << '\n' << s2 << '\n' << s3;
	if (s3.size() != s1.size() + s2.size()) {
		cout << "false";
		return 0;
	}

	if (s1.size() < s2.size()) swap(s1, s2); // it will always either be equal or s1 having more to check

	int i1 = 0, i2 = 0;

	// int e1 = min(s1.size(), s2.size());
	try {
			for (int i = 0; i < s3.size(); i++) {
			if (s1[i1] == s3[i]) i1++;
			else if (s2.size() >= i2 && s2[i2] == s3[i]) i2++;
			else if (s2.size() < i2) {
				// well then we got:
				// s1[i1] != s3[i]
				// s2.size() < i2 (i2 is already going too far)
				// so?
				cout << "false";
				return 0;
			} else {
				cout << "false";
				return 0;
			}
		}
	} catch (const exception& e) { // ngl i might not be able to hold all of them so...
		cout << "false";
		return 0;
	}

	cout << "true";
	return 0;
}