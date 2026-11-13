#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	if (a - b == 1 && a - c == 2 || a - b == 2 && a - c == 1 || b - a == 1 && b - c == 2 || b - a == 2 && b - c == 1 || c - b == 1 && c - a == 2 || c - b == 2 && c - a == 1) cout << "YES" << "\n";
	else cout << "NO" << "\n";
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