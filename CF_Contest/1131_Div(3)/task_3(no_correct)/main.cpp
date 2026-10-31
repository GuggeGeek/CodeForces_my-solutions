#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<long long> pref(n, 0);
	bool flag = false;
	cin >> pref[0];
	if (pref[0] != 1) flag = true;
	for (int l = 1; l < n; l++) {
		int a;
		cin >> a;
		pref[l] = pref[l - 1] + a;
		if (!flag && a != 1) flag = true;
	}

	if (!flag) {
		cout << -1 << "\n";
		return;
	}

	cout << pref[n - 1] - 1 << "\n";
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