#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    freopen("KHACNHAU.INP", "r", stdin);
    freopen("KHACNHAU.OUT", "w", stdout);

	vector<int> nums;
	int x;
	while (cin >> x) {
        nums.push_back(x);
	}

	// Man this fucking sucks... Uhhh... Coulda lower bound but fuck it man
	set<int> kms;
	for (const int& x : nums) {
        // cout << ">" << x << "\n";
        kms.insert(x);
	}
	cout << kms.size();
}
