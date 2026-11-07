// 1601A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<int> st(30, 0);
	for (int l = 0; l < n; l++) {
		int a = 0;
		cin >> a;
		for (int j = 0; j < 30; j++) {
			if (a & (1 << j)) st[j]++;
		}
	}

	for (int k = 1; k <= n; k++) {
		bool ok = true;
		for (int b = 0; b < 30; b++) {
			if (st[b] % k != 0) {
				ok = false;
				break;
			}
		}
		if (ok) cout << k << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t;l++) {
		solve();
	}

	return 0;
}