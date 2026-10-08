#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> nums;
	
	while (true) {
		string x;
		getline(cin, x);
		
		ios::iostate flags = cin.rdstate();
		if (flags & ios::eofbit || flags & ios::failbit || flags & ios::badbit || x == "") {
			break;
		}
		
		try {
			nums.push_back(stoi(x));
		} catch (const std::exception& e) {
			// Break ig
			break;
		}
	}
	
	if (nums.size() > 0) cout << nums[nums.size() / 2];
	
	return 0;
}