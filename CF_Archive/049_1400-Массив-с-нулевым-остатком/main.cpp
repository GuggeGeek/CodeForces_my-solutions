// 1374D
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void solve() {
	int n = 0;
	long long k = 0, ans = 0;
	cin >> n >> k;
	map<long long, int> dp;

	for (int l = 0; l < n; l++) {
		long long a = 0;
		cin >> a;
		if (a % k != 0) {
			long long x = k - a % k;
			ans = max(ans, x + dp[x] * k);
			dp[x]++;
		}
	}

	if(ans == 0) cout << ans << "\n";
	else cout << ans + 1 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) solve();

	return 0;
}