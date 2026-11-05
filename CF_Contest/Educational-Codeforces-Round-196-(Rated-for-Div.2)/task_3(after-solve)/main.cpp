#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0, xo = 0, o = 0;
	cin >> n;
	for (int l = 1; l <= n; l++) {
		xo = xo ^ l;
		o = o | l;
	}
	int goal = o * 2;
	int delta = goal ^ xo; // v xor 2v   ||   delta xor v = 2v
	int v = 0, cur = 0;

	if (__builtin_popcount(delta) % 2 != 0) {
		goal = o * 2 + 1;
		delta = goal ^ xo;
	}

	for (int l = 0; l < 19; l++) {
		if ((1 << l) & delta) cur ^= 1;
		if (cur == 1) {
			v |= (1 << l);
		}
	}

	vector<int> ans(n + 1, 0);

	if (v <= n) ans[v] = 1;
	else {
		int high = 1 << __lg(v);
		ans[high] = 1;
		ans[v ^ high] = 1;
	}

	for (int l = 1; l <= n; l++) {
		cout << ans[l] << " ";
	}
	cout << "\n";
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