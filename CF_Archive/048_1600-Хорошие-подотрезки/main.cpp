// 1398C
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void solve() {
	int n = 0, act = 0;
	long long ans = 0;
	string s;
	map <int, int> st;
	cin >> n >> s;

	for (auto now : s) {
		int ch = now - '0' - 1;
		act += ch;
		if (act == 0) ans++;

		if (st.contains(act)) {
			ans += st[act];
			st[act]++;
		}
		else st[act] = 1;
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0;l < t; l++) {
		solve();
	}

	return 0;
}