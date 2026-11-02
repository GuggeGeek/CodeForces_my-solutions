// 1520D
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	long long ans = 0;
	cin >> n;
	vector<int> st(2 * n + 7, 0);
	for (int l = 0; l < n; l++) {
		int a = 0;
		cin >> a;
		int raz = a - l;
		ans += st[n + raz];
		st[n + raz]++;
	}
	cout << ans << "\n";
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