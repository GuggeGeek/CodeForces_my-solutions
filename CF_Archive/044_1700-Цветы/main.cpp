// 474D
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k = 0;
const long long mod = 1e9 + 7;
vector<long long> pref(100001, 0);

void solve() {
	int a = 0, b = 0;
	cin >> a >> b;

	cout << (pref[b] - pref[a - 1] + mod) % mod << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t >> k;
	vector<long long> dp(100001, 0);
	dp[0] = 1;

	for (int l = 1; l < 100001; l++) {
		if (l - k >= 0) dp[l] = (dp[l] + dp[l - 1] + dp[l - k]) % mod;
		else dp[l] = (dp[l] + dp[l - 1]) % mod;
		pref[l] = (pref[l] + pref[l-1] + dp[l]) % mod;
	}

	for (int l = 0; l < t; l++) {
		solve();
	}

	return 0;
}