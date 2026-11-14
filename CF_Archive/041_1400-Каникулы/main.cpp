// 698A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, last = 0;
	cin >> n;

	vector<vector<int>> st(3, vector<int>(n+1, INF));
	st[0][0] = 0; st[1][0] = 0, st[2][0] = 0;

	for (int l = 1; l <= n; l++) {
		int a = 0;
		cin >> a;
		st[0][l] = min(st[0][l - 1], min(st[1][l - 1], st[2][l - 1])) + 1;

		if (a == 1 || a == 3) st[1][l] = min(st[0][l - 1], st[2][l - 1]);
		if (a == 2 || a == 3) st[2][l] = min(st[0][l - 1], st[1][l - 1]);

	}

	cout << min(st[0][n], min(st[1][n], st[2][n])) << "\n";

	return 0;
}