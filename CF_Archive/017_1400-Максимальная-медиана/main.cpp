// 1201C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(const vector<long long>& st, long long mid) {
	long long ans = 0;
	for (int l = st.size() / 2; l < st.size(); l++) {
		if (mid - st[l] > 0) ans += mid - st[l];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	long long k = 0;
	cin >> n >> k;
	vector<long long> st(n);
	for (int l = 0; l < n; l++) cin >> st[l];

	sort(st.begin(), st.end());
	
	long long l = 1, r = 2 * 1e9, ans = r;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (solve(st, mid) <= k) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << "\n";

	return 0;
}