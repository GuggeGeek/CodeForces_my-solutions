#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<long long> st(n, 0);
	for (int l = 0; l < n; l++) {
		cin >> st[l];
	}
	sort(st.begin(), st.end());

	int ans = 1e9 + 7;
	for (int l = 0; l < n; l++) {
		int del = l;
		long long a = st[l];
		for (int i = l + 1; i < n; i++) {
			if (max(a, st[i]) % min(a, st[i]) != 0) del++;
		}
		ans = min(ans, del);
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