// 1857C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	vector<long long> st(n * (n - 1) / 2, 0);
	for (int l = 0; l < n * (n - 1) / 2; l++) cin >> st[l];
	sort(st.begin(), st.end());

	int ind = 0;
	for (int l = n - 1; l >= 1; l--) {
		cout << st[ind] << " ";
		ind += l;
	}
	cout << 1000000000 << "\n";
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