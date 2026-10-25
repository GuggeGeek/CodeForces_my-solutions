// 279B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, k = 0;
	cin >> n >> k;
	vector<long long> pref(n + 1, 0);
	for (int l = 1; l <= n; l++) {
		cin >> pref[l];
		pref[l] += pref[l - 1];
	}

	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		int m = upper_bound(pref.begin(), pref.end(), k + pref[i - 1]) - pref.begin() - i;
		maxi = max(maxi, m);
	}

	cout << maxi << "\n";

	return 0;
}