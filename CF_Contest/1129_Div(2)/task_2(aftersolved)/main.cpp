#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> st(200001, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) {
		int n = 0;
		cin >> n;
		long long mini = 1e18;
		for (int j = 0; j < n; j++) {
			cin >> st[j];
			mini = min(mini, st[j]);
		}

		if (mini <= n - 1) cout << n << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}