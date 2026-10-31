#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0, m = 0;
	cin >> n >> m;
	if (n < 3) {
		cout << "NO" << "\n";
		return;
	}
	vector<int> a(26, 0); // 18 8 23
	vector<int> b(26, 0);
	for (int l = 0; l < n; l++) {
		char r;
		cin >> r;
		a[r - 'a']++;
	}
	for (int l = 0; l < m; l++) {
		char r;
		cin >> r;
		b[r - 'a']++;
	}

	for (int l = 0; l < 26; l++) {
		a[l] -= b[l];
	}

	if (a[8] == 1 && a[18] == 1 && a[23] == 1) {
		for (int l = 0; l < 26; l++) {
			if (l == 18 || l == 8 || l == 23) {
				continue;
			}
			if (a[l] != 0) {
				cout << "NO" << "\n";
				return;
			}
		}
	}
	else {
		cout << "NO" << "\n";
		return;
	}

	cout << "YES" << "\n";
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