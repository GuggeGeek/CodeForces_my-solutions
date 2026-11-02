// 1472D
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<long long> st(n, 0);
	for (int l = 0; l < n; l++) cin >> st[l];

	sort(st.begin(), st.end());
	bool r = false;
	long long a = 0, b = 0;
	for (int l = n - 1;l >= 0; l--) {
		if (!r) { // ходит алиса
			if (st[l] % 2 == 0) a += st[l];
			r = true;
		}
		else {
			if (st[l] % 2 == 1) b += st[l];
			r = false;
		}
	}

	if (a > b) cout << "Alice" << "\n";
	else if (a < b) cout << "Bob" << "\n";
	else cout << "Tie" << "\n";
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