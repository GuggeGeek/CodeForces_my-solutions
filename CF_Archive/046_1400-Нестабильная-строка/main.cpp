// 1535C
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve() {
	string s;
	cin >> s;
	vector<vector<int>> st(2, vector<int>(s.size(), 0));
	long long ans = 0;

	int ch = 0;

	for (auto now : s) {
		if (now == '0' || now == '?') st[0][ch] = 1;
		if (now == '1' || now == '?') st[1][ch] = 1;

		ans += max(st[1][ch], st[0][ch]);
		ch++;
		break;
	}
	ch = 0;
	for (auto now : s) {
		if (ch == 0) {
			ch++;
			continue;
		}
		if (now == '0' || now == '?') st[0][ch] = st[1][ch - 1] + 1;
		else st[0][ch] = 0;
		if (now == '1' || now == '?') st[1][ch] = st[0][ch - 1] + 1;
		else st[1][ch] = 0;

		ans += max(st[1][ch], st[0][ch]);
		ch++;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	for (int l = 0; l < n; l++) {
		solve();
	}

	return 0;
}