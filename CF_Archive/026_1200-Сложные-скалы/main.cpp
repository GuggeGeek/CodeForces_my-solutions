// 1537C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0, ind = 0;
	cin >> n;
	vector <long long> st(n, 0);
	for (int l = 0; l < n; l++) cin >> st[l];

	sort(st.begin(), st.end());

	long long raz = 1e9 + 7;
	for (int l = 1; l < n; l++) {
		if (st[l] - st[l - 1] < raz) {
			ind = l;
			raz = st[l] - st[l - 1];
		}
	}
	if (n == 2) {
		cout << min(st[0], st[1]) << " " << max(st[0], st[1]) << "\n";
		return;
	}
	for (int l = ind; l < n; l++) cout << st[l] << " ";
	for (int l = 0; l < ind; l++) cout << st[l] << " ";
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