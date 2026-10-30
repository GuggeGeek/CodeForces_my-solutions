// 1850E
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool chek(const vector<int> &st, long long mid, long long c) {
	long long ans = 0;
	for (auto now : st) {
		ans += (now + mid * 2) * (now + mid * 2);
		if (ans > c) return false;
	}
	return true;
}

void solve() {
	int n = 0;
	long long c = 0;
	cin >> n >> c; // картин и см картона
	vector<int> st(n, 0); // размеры картин
	for (int l = 0; l < n; l++) {
		cin >> st[l];
	}

	long long l = 1, r = 1e9 + 7, ans = 1;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (chek(st, mid, c)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << "\n";
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