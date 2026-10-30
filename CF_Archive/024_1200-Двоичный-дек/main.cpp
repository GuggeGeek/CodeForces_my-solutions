// 1692E
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0, s = 0, test = 0, l = 0, r = -1, ans = 0, sum = 0;
	cin >> n >> s; // кол-во и необход сумма элементов
	vector<int> st(n, 0);
	for (int j = 0; j < n; j++) {
		cin >> st[j];
		test += st[j];
		if (test == s && r == -1) {
			r = j;
			sum = test; // сумма на отрезке r - l + 1
			ans = r + 1; // длинна лучшего отрезка содержащего s
		}
	}
	if (test < s) cout << -1 << "\n";
	else {
		while (r < n - 1) {
			r++;
			sum += st[r];
			while (sum > s) {
				sum -= st[l++];
			}
			ans = max(ans, r - l + 1);
		}
		cout << n - ans << "\n";
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