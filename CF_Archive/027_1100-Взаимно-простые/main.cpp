// 1742D
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void solve() {
	int n = 0;
	cin >> n;
	vector<int> st(n, 0);
	for (int l = 0; l < n; l++) cin >> st[l];

	int i = 0, j = 0;
	vector<int> last(1001, 0);
	for (int l = n; l > 0; l--) {
		if (last[st[l - 1]] == 0) last[st[l - 1]] = l;
	}

	int ans = -1;
	for (int r = 1; r <= 1000; r++) {
		if (last[r] == 0) continue;
		for (int l = r; l <= 1000; l++) {
			if (last[l] == 0) continue;
			if (gcd(r, l) == 1) {
				ans = max(ans, last[l] + last[r]);
			}
		}
	}

	cout << ans << "\n";
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