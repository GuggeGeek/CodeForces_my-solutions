// 1669H
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

void solve() {
	int n = 0;
	long long k = 0;
	cin >> n >> k;
	vector<int> st(31, 0);
	for (int l = 0; l < n; l++) {
		int a = 0;
		cin >> a;
		for (int j = 30; j >= 0; j--) {
			if (a & (1 << j)) st[j]++;
		}
	}

	vector<pair<int, int>> need(31, pair(0, 0)); // сколько нужно до n || БИТ
	for (int l = 0; l < 31; l++) {
		need[l] = pair(n - st[l], l);
	}

	sort(need.begin(), need.end());

	while (!need.empty() && k >= need[0].first) {
		int maxi = 0, ind = 0;
		for (int l = 0; l < need.size(); l++) {
			if (k < need[l].first) break;
			if (need[l].second > maxi) {
				maxi = need[l].second;
				ind = l;
			}
		}

		k -= need[ind].first;
		st[maxi] = n;
		need.erase(need.begin() + ind);
	}

	long long ans = 0;
	for (int l = 0; l < 31; l++) {
		if (st[l] == n) ans += (1 << l);
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