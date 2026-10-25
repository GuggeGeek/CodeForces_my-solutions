// 1676E
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
		int n = 0, q = 0;
		cin >> n >> q;
		vector<int> st(n, 0);
		for (int l = 0; l < n; l++) {
			cin >> st[l];
		}

		sort(st.rbegin(), st.rend());
		vector<long long> pref(n, 0);
		pref[0] = st[0];
		for (int l = 1; l < n; l++) {
			pref[l] = pref[l - 1] + st[l];
		}

		for (int l = 0; l < q; l++) {
			long long a = 0;
			cin >> a;
			auto lw = lower_bound(pref.begin(), pref.end(), a);
			if (lw != pref.end()) cout << lw - pref.begin() + 1 << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;
}