// 1692F
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<int> st(10, 0);
	for (int l = 0; l < n; l++) {
		long long a = 0;
		cin >> a;
		st[a % 10]++;
	}

	for (int i = 0; i < 10; i++) {
		for (int l = 0; l < 10; l++) {
			for (int r = 0; r < 10; r++) {
				if ((r + i + l) % 10 != 3) continue;
				st[i]--; st[l]--; st[r]--;
				if (st[i] >= 0 && st[l] >= 0 && st[r] >= 0) {
					cout << "YES" << "\n";
					return;
				}
				st[i]++; st[l]++; st[r]++;
			}
		}
	}
	cout << "NO" << "\n";
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