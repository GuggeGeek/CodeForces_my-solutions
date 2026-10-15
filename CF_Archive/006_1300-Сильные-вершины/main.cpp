// 1857D
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
		int n = 0;
		cin >> n;
		vector<long long> a(n, 0);
		for(int j = 0; j < n; j++){
			cin >> a[j];
		}
		vector<long long> pr(n, 0);
		long long maxi = -1e18;
		for (int j = 0; j < n; j++) {
			long long b = 0;
			cin >> b;
			pr[j] = a[j] - b;
			maxi = max(maxi, pr[j]);
		}

		vector<int> ans;
		for (int j = 0; j < n; j++) {
			if (pr[j] == maxi) ans.push_back(j + 1);
		}
		cout << ans.size() << "\n";

		sort(ans.begin(), ans.end());

		for (auto now : ans) {
			cout << now << " ";
		}
		cout << "\n";
	}

	return 0;
}