// 1927D
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) { // запусков
		int n = 0;
		cin >> n;
		vector<int> orig(n + 5);
		vector<int> sdv(n + 5, 0);
		cin >> orig[1];
		for (int j = 2; j <= n; j++) {
			cin >> orig[j];
			if (orig[j - 1] != orig[j]) {
				sdv[j] = j - 1;
			}
			else {
				sdv[j] = sdv[j - 1];
			}
		}

		int q = 0;
		cin >> q;
		for (int j = 0; j < q; j++) {
			int a, b;
			cin >> a >> b;

			if (sdv[b] < a) {
				cout << -1 << " " << -1 << "\n";
				continue;
			}

			cout << b << " " << sdv[b] << "\n";
		}
		cout << "\n";
	}

	return 0;
}