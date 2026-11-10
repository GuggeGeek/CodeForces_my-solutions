// 1628A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<int> st(n, 0);
	vector<int> ans;
	for (int l = 0; l < n; l++) cin >> st[l];

	vector<int> suf(n + 1, 0);
	vector<bool> ok(n + 2, false);

	ok[st[n - 1]] = true;
	if (st[n - 1] == 0) suf[n - 1] = 1;
	else suf[n - 1] = 0;
	for (int l = n - 2; l > -1; l--) {
		ok[st[l]] = true;
		for (int j = suf[l + 1]; j <= n + 1; j++) {
			if (!ok[j]) {
				suf[l] = j;
				break;
			}
		}
	}

	int left = 0;
	while (left <= n - 1) {
		int target = suf[left], act = 0;
		if (target == 0) {
			ans.push_back(0);
			left++;
			continue;
		}
		vector<bool> b(target, false);
		while(left < n && act < target) {
			if (st[left] < target && !b[st[left]]) {
				b[st[left]] = true;
				act++;
			}
			left++;
		}
		ans.push_back(target);
	}
	cout << ans.size() << "\n";
	for (auto now : ans) {
		cout << now << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t;l++) {
		solve();
	}

	return 0;
}