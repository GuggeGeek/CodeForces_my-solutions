// 1272D
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> st(n, 0);
	vector<vector<long long>> dp(n, vector<long long>(2, 1)); dp[0][1] = 0; // 1 = потрачено 0 = цело

	for (int l = 0; l < n; l++) cin >> st[l];

	for (int l = 1; l < n; l++) {
		if (st[l - 1] < st[l]) {
			dp[l][0] = dp[l - 1][0] + 1;
			dp[l][1] = max(dp[l][1], dp[l - 1][1] + 1);
		}
		if (l >= 2 && st[l - 2] < st[l]) {
			dp[l][1] = max(dp[l][1], dp[l - 2][0] + 1);
		}
	}

	long long ans = 0;
	for (int l = 0; l < n; l++) {
		ans = max(dp[l][1], max(dp[l][0], ans));
	}
	cout << ans;
	return 0;
}