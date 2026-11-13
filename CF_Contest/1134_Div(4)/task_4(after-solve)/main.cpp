#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	long long ans = 0;
	cin >> n;
	vector<int> st(n, 0);
	vector<bool> jump(26, false);

	for (int l = 0; l < n; l++) {
		char a;
		cin >> a;
		st[l] = a - 'a';
	}

	int l = 0, r = n - 1;
	while (l <= r) {
		if (st[l] < st[r]) swap(st[l], st[r]);
		for (int j = st[r] + 1; j <= st[l]; j++) {
			jump[j] = true;
		}
 		l++; r--;
	}

	for (int j = 1; j < 26; j++) if (jump[j]) ans += 1;

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