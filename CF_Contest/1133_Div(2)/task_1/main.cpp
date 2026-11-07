#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> a(2, 0); // 0 чет 1 нечет
	vector<int> b(2, 0);
	for (int l = 0; l < n; l++) {
		int r = 0;
		cin >> r;
		a[r % 2]++;
	}
	for (int l = 0; l < n; l++) {
		int r = 0;
		cin >> r;
		b[r % 2]++;
	}

	if (k % 2 == 0) { // стать четным
		if (b[1] > a[1]) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
	else {
		if (b[0] > a[0]) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
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