// 1793C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<int> st(n, 0);
	for (int l = 0; l < n; l++) {
		cin >> st[l];
	}

	int mini = 1, maxi = n, l = 0, r = n - 1;

	while (r - l + 1 >= 4) {
		if (st[l] == maxi || st[l] == mini) {
			if (st[l] == maxi) maxi--;
			else mini++;
			l++;
		}
		else {
			if (st[r] != maxi && st[r] != mini) {
				cout << l + 1 << " " << r + 1 << "\n";
				return;
			}
		}
		if (st[r] == maxi || st[r] == mini) {
			if (st[r] == maxi) maxi--;
			else mini++;
			r--;
		}
		else {
			if (st[l] != maxi && st[l] != mini) {
				cout << l + 1 << " " << r + 1 << "\n";
				return;
			}
		}
	}
	cout << -1 << "\n";
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