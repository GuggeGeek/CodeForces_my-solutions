// 1873F
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		long long k = 0;
		cin >> n >> k;
		vector<int> a(n, 0);
		vector<int> h(n, 0);
		for (int j = 0; j < n; j++) cin >> a[j];
		for (int j = 0; j < n; j++) cin >> h[j];

		int l = 0, ans = 0;
		long long sum = 0;

		for (int r = 0; r < n; r++) {
			if (r > 0 && h[r - 1] % h[r] != 0) {
				l = r;
				sum = 0;
			}

			sum += a[r];

			while (sum > k) {
				sum -= a[l];
				l++;
			}

			ans = max(ans, r - l + 1);
		}
		cout << ans << "\n";
	}

	return 0;
}