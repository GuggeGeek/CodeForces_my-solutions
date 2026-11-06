// 1722G
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	int xo = 0;
	for (int l = 1; l <= n - 3; l++) {
		cout << l << " ";
		xo ^= l;
	}

	int y1 = 1 << 30, y2 = 1 << 29, y3 = xo ^ y2 ^ y1;
	cout << y1 << " " << y2 << " " << y3 << "\n";
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