#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0, sum = 0;
	int ind0 = 0, ind1 = 0;
	cin >> n;
	bool flag1 = false, flag2 = false; // 1 внеш // 2 внутренний
	for (int l = 0; l < n; l++) {
		int a;
		cin >> a;
		sum += a;
		if (l == 0) {
			ind0 = a;
			if (a != 1) flag1 = true;
		}
		else if (l == n - 1) {
			ind1 = a;
			if (a != 1) flag1 = true;
		}
		else if (!flag2 && l > 0 && l < n - 1 && a != 1) flag2 = true;
	}

	if (!flag2) {
		if (!flag1) cout << -1 << "\n";
		else cout << ind1 + ind0 - 1 << "\n";
		return;
	}

	cout << sum - 1 << "\n";
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