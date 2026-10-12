#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<int> g(5, 0);
	for (int l = 0; l < n; l++) {
		int a = 0;
		cin >> a;
		g[a]++;
	}

	int ans = g[4];
	while (g[3] > 0 && g[1] > 0) {
		g[1]--;
		g[3]--;
		ans++;
	}
	while (g[3] > 0) {
		g[3]--;
		ans++;
	}
	int ost = 0;
	ans += g[2] / 2;
	g[2] %= 2;
	if (g[2] > 0) ost = 2;

	ans += g[1] / 4;
	g[1] %= 4;
	ost += g[1];
	ans += (ost + 3) / 4;

	cout << ans;

	return 0;
}