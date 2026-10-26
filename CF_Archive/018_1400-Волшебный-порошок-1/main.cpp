// 670D1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(const vector<long long>& need, const vector<long long>& inv, long long pie) {
	long long ans = 0;
	for (int l = 0; l < need.size(); l++) {
		if (need[l] * pie > inv[l]) ans += need[l] * pie - inv[l];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, k = 0;
	cin >> n >> k;
	vector<long long> need(n, 0);
	vector<long long> inv(n, 0);
	for (int l = 0; l < n; l++) {
		cin >> need[l];
	}
	for (int l = 0; l < n; l++) {
		cin >> inv[l];
	}

	long long l = 0, r = 2 * 1e9 + 7, ans = r;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (solve(need, inv, mid) <= k) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ans;
	return 0;
}