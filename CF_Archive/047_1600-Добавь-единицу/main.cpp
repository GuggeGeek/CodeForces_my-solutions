// 1513C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long long>> dp(200010, vector<long long>(10, 1));
const long long mod = 1e9 + 7;

void solve() {
	long long n = 0, ans = 0;
	int m = 0;
	cin >> n >> m;

	while (n > 0) {
		int ch = n % 10;
		ans = (ans + dp[m][ch]) % mod;
		n /= 10;
	}

	cout << ans << "\n";
}

void in() {
	for (int l = 1; l < 200009; l++) {
		for (int j = 0; j < 10; j++) {
			if (j == 9) dp[l][j] = (dp[l - 1][0] + dp[l - 1][1]) % mod;
			else dp[l][j] = dp[l - 1][j + 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;

	in();
	for (int l = 0; l < t; l++) {
		solve();
	}

	return 0;
}