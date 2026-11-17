// 1324E
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, h = 0, l = 0, r = 0;
	cin >> n >> h >> l >> r;
	vector<vector<int>> st(n + 1, vector<int>(h, -1));
	st[0][0] = 0;

	for (int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		for (int j = 0; j < h; j++) {
			if (st[i][j] > -1) {
				if ((j + a) % h >= l && (j + a) % h <= r) st[i + 1][(j + a) % h] = max(st[i][j] + 1, st[i + 1][(j + a) % h]);
				else st[i + 1][(j + a) % h] = max(st[i][j], st[i + 1][(j + a) % h]);
				if ((j + (a - 1)) % h >= l && (j + (a - 1)) % h <= r) st[i + 1][(j + (a - 1)) % h] = max(st[i][j] + 1, st[i + 1][(j + (a - 1)) % h]);
				else st[i + 1][(j + (a - 1)) % h] = max(st[i][j], st[i + 1][(j + (a - 1)) % h]);
			}
		}
	}

	cout << *max_element(st[n].begin(), st[n].end());

	return 0;
}