#include <bits/stdc++.h>
using namespace std;
#define BUFSIZE 5

int main() {
	int n;
	cin >> n;
	
	pair<string, string> tu;
	for (int i = 0; i < n; i++) {
		cin >> tu.first >> tu.second;
		
		cout << tu.second << " " << tu.first << '\n';
	}
	
	return 0;
}