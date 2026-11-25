// 1350B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<long long>st(n + 1, 0);
	vector<long long>dp(n + 1, 1);
	for (int l = 1; l <= n; l++) {
		cin >> st[l];
	}

	for (int l = 1; l <= n; l++) {
		int ind = l + l;
		while (ind <= n) {
			if (st[ind] > st[l]) dp[ind] = max(dp[ind], dp[l] + 1);
			ind += l;
		}
	}

	cout << *max_element(dp.begin() + 1, dp.end()) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) solve();

	return 0;
}