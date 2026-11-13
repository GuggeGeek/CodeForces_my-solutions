#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve() {
	int n = 0, ans = 0;
	cin >> n;
	bool red = true; // красн = R || синий B
	string st;
	
	for (int l = 0; l < n; l++) {
		char h;
		cin >> h;
		st += h;
	}

	for (auto now : st) {
		if (now == 'R') {
			if (!red) {
				ans++;
				if (red == true) red = false;
				else red = true;
			}
		}
		else {
			if (red) {
				ans++;
				if (red == true) red = false;
				else red = true;
			}
		}

		if (red == true) red = false;
		else red = true;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) {
		solve();
	}

	return 0;
}