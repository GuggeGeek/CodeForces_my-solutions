#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0, maxi = -1, ind = 0;
	cin >> n;
	vector<int> st(n + 7, 0), raz(n + 7, 0), l(n + 7, 0), r(n + 7, 0);
	cin >> st[0];
	for (int j = 0; j < n - 1; j++) {
		cin >> st[j + 1];
		raz[j] = abs(st[j] - st[j + 1]);
		if (raz[j] > maxi) {
			ind = j;
			maxi = raz[j];
		}
		l[j] = abs(st[j] * 2 - st[j + 1]);
		r[j] = abs(st[j] - st[j + 1] * 2);
	}
	int lev = ind - 1, ri = ind + 1;
	if (lev == -1) lev = ind;
	if (ri == n - 1) lev = ind;
	raz[ind] = min(l[ind], raz[ind]);
	raz[ind] = min(r[ind], raz[ind]);

	bool flag1 = true, flag2 = true;
	while (flag1 || flag2) {
		if (flag1 && l[lev] <= raz[lev] || r[lev] <= raz[lev]) {
			raz[lev] = min(l[lev], r[lev]);
			if (lev != 0) lev--;
			else flag1 = false;
		}
		else flag1 = false;
		if (flag2 && l[ri] <= raz[ri] || r[ri] <= raz[ri]) {
			raz[ri] = min(l[ri], r[ri]);
			if (lev != 0) ri++;
			else flag2 = false;
		}
		else flag2 = false;
	}
	sort(raz.rbegin(), raz.rend());
	cout << raz[0] << "\n";
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