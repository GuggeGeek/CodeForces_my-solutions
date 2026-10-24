#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) {
		int n, k;
		cin >> n >> k;
		vector<int> st(n + 1, 0);
		for (int j = 0; j < n; j++) {
			int a = 0;
			cin >> a;
			st[a]++;
		}

		int ost = 0;
		for (int j = 0; j <= n; j++) {
			if (st[j] >= k) ost += st[j] - k;
			else if (st[j] + ost >= k && st[j] > 0) ost = st[j] + ost - k;
			else {
				cout << j << "\n";
				break;
			}
		}
	}

	return 0;
}