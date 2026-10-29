// 1324D
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> a(n, 0);
	vector<long long> st(n, 0);
	for (int l = 0; l < n; l++) {
		cin >> a[l];
	}
	for (int l = 0; l < n; l++) {
		cin >> st[l];
		st[l] = a[l] - st[l];
	}

	sort(st.begin(), st.end());

	long long ans = 0;
	for (int l = 0; l < n; l++) {
		auto it = upper_bound(st.begin() + l + 1, st.end(), -st[l]) - st.begin();
		ans += st.size() - it;
	}
	cout << ans;

	return 0;
}