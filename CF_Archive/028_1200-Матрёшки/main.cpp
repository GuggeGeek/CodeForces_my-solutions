// 1790D
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	map<long long, int> len;
	set<long long> st;
	for (int l = 0; l < n; l++) {
		long long a = 0;
		cin >> a;
		st.insert(a);
		len[a] += 1;
	}

	long long ans = 0, last = -1;
	for (auto now : st) {
		if (now - last > 1) {
			ans += len[now];
		}
		else if (len[now] > len[last]) {
			ans += len[now] - len[last];
		}

		last = now;
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