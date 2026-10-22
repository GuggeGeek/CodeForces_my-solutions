// 1736C1
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
		cin >> n;
		vector<int> st(n + 1, 0);
		for (int j = 1; j <= n; j++) {
			cin >> st[j];
		}

		int l = 1;
		long long ans = 0;
		for (int r = 1; r <= n; r++) {
			l = max(l, r - st[r] + 1);
			ans += r - l + 1;
		}
		cout << ans << "\n";
	}

	return 0;
}