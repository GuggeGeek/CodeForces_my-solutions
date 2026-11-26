// 1881E
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<int> st(n, 0);
	vector<int> dp(n + 1, 1e9);
	for (int l = 0; l < n; l++) cin >> st[l];
	dp[0] = 0;

	for (int l = 0; l < n; l++) {
		dp[l + 1] = min(dp[l + 1], dp[l] + 1);
		int jump = st[l] + l + 1;
		if (jump <= n) {
			dp[jump] = min(dp[jump], dp[l]);
		}
	}

	cout << dp[n] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) solve();

	return 0;
}