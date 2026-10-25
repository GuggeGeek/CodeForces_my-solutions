// 1613C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(const vector<long long>& raz, long long poten) {
	long long answ = 0;
	for (auto now : raz) {
		if (now == 0) answ += poten;
		else answ += min(poten, now);
	}
	return answ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		long long h = 0;
		cin >> n >> h;
		vector<long long> raz(n, 0); // x x x 0
		vector<long long> times(n, 0);  
		for (int l = 0; l < n; l++) {
			cin >> times[l];
		}

		for (int l = 1; l < n; l++) {
			raz[l - 1] = times[l] - times[l - 1];
		}

		long long l = 1, r = h, ans = h;
		while (l <= r) {
			long long mid = l + (r - l) / 2; // или mid_point из numeric
			if (solve(raz, mid) >= h) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << "\n";
	}

	return 0;
}