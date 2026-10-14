//1931D
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) {
		int n = 0;
		long long x = 0, y = 0, ans = 0;
		cin >> n >> x >> y;
		map <pair<long long, long long>, int> list;
		for (int j = 0; j < n; j++) {
			long long a = 0;
			cin >> a;

			long long actx = a % x;
			long long acty = a % y;

			long long xn = (x - actx) % x;

			if (list.contains(pair(xn, acty))) ans += list[pair(xn, acty)];
			list[pair(actx, acty)]++;
		}

		cout << ans << "\n";
	}

	return 0;
}