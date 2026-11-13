#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0, sum = 0;
	cin >> n;
	vector<long long> h(n, 0), ans(n, 0);
	for (int j = 0; j < n; j++) {
		cin >> h[j];
	}

	sort(h.begin(), h.end());

	long long l = -1, r = -1;
	int lind = 0, rind = n - 1;
	for (auto now : h) {
		if (now <= l && now <= r) {
			ans[lind] = now;
			lind++;
			l = now;
		}
		else if(now > r){
			sum++;
			ans[rind] = now;
			rind--;
			r = now;
		}
		else {
			sum++;
			ans[lind] = now;
			lind++;
			l = now;
		}
	}

	cout << sum << "\n";
	for (auto now : ans) cout << now << " ";
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