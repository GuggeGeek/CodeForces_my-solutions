// 2025C
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
		int n = 0, k = 0;
		cin >> n >> k;
		vector<long long> st(n, 0);
		for (int j = 0; j < n; j++) {
			cin >> st[j];
		}
		sort(st.begin(), st.end());

		vector<int> kol(1, 1);
		int s = 0;
		for (int j = 1; j < n; j++) {
			if (st[j] - st[j - 1] == 0) kol[s]++;
			else if (st[j] - st[j - 1] == 1) {
				kol.push_back(1);
				s++;
			}
			else {
				kol.push_back(0);
				kol.push_back(1);
				s += 2;
			}
		}

		int l = 0, ans = 0, act = 0;
		for (int r = 0; r < kol.size(); r++) {
			while (r - l + 1 > k) {
				act -= kol[l];
				l++;
			}
			if (kol[r] == 0) {
				act = 0;
				l = r + 1;
			}
			else {
				act += kol[r];
				ans = max(ans, act);
			}
		}

		cout << ans << "\n";
	}

	return 0;
}