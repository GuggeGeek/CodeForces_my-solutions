#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		long long l = 0, r = 0;
		cin >> n >> l >> r;
		vector<long long> st(n, 0);
		for (int p = 0; p < n; p++) {
			cin >> st[p];
		}
		sort(st.begin(), st.end());
		long long ans = 0;
		for (int t = 0; t < n; t++) {
			auto lw = lower_bound(st.begin() + t + 1, st.end(), l - st[t]);
			auto ub = upper_bound(st.begin() + t + 1, st.end(), r - st[t]);

			ans += ub - lw;
		}
		cout << ans << "\n";
	}

	return 0;
}