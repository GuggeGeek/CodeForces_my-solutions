// 1873E
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(const vector<long long>& cor, long long h) {
	long long ans = 0;
	for (auto now : cor) {
		if (now < h) ans += h - now;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		long long x = 0;
		cin >> n >> x;
		vector<long long> cor(n);
		for (int l = 0; l < n; l++) cin >> cor[l];

		long long l = 0, r = (2 * 1e9), h = r;
		while (l <= r) {
			long long mid = l + (r - l) / 2;
			if (solve(cor, mid) <= x) {
				h = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << h << "\n";
	}

	return 0;
}