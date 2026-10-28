// 2272C
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool chek(const vector<long long>& st, long long mid, long long x) {
	long long ok = 1, alone = 0;

	for (int l = 1; l < st.size(); l++) {
		long long bridge = min(alone, ok) + (st[l] - st[l - 1] - 1) / mid;

		long long newalone = ok;
		long long buy = ok + 1;

		alone = newalone;
		ok = min(bridge, buy);
	}

	if (ok <= x) return true;
	else return false;
}

void solve(){
	int n = 0, x = 0;
	cin >> n >> x;
	vector<long long> st(n, 0);
	for (int l = 0; l < n; l++) {
		cin >> st[l];
	}

	long long l = 1, r = 1e9 + 7, ans = r;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (chek(st, mid, x)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}

	return 0;
}