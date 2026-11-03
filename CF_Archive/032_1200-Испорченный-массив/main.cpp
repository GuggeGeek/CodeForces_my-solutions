// 1512D
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	long long total = 0;
	vector<long long> st(n + 2, 0);
	for (int l = 0; l <= n + 1; l++) {
		cin >> st[l];
	}

	sort(st.begin(), st.end());

	for (int l = 0; l <= n; l++) {
		total += st[l];
	}

	auto it = lower_bound(st.begin(), st.begin() + n + 1, total - st[n + 1]);
	if (it != st.begin() + n + 1 && total - st[n + 1] == *it) {
		for (int l = 0; l <= n; l++) {
			if (l != it - st.begin()) cout << st[l] << " ";
		}
	}
	else {
		total -= st[n];
		if (total == st[n]) {
			for (int l = 0; l < n; l++) {
				cout << st[l] << " ";
			}
		}
		else cout << -1;
	}
	cout << "\n";
	return;
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