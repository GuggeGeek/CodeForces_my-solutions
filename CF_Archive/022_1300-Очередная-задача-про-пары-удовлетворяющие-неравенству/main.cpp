// 1703F
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<long long> st, ind;
	for (int l = 0; l < n; l++) {
		long long a;
		cin >> a;
		if (a < l + 1) {
			st.push_back(a);
			ind.push_back(l + 1);
		}
	}

	long long ans = 0;
	for (int l = 0; l < st.size(); l++) {
		ans += lower_bound(ind.begin(), ind.end(), st[l]) - ind.begin();
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) {
		solve();
	}

	return 0;
}