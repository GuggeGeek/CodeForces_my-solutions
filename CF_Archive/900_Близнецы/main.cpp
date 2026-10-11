#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, sum = 0, sums = 0, ans = 0;
	cin >> n;
	vector<int> mon(n, 0);
	for (int l = 0; l < n; l++) {
		int a = 0;
		cin >> a;
		sum += a;
		mon[l] = a;
	}
	int pol = sum / 2; pol++;// гарантом минимально нужное

	sort(mon.begin(), mon.end());

	for (int l = n - 1; l >= 0; l--) {
		if (sums < pol) {
			sums += mon[l];
			ans++;
		}
		else break;
	}

	cout << ans;
	return 0;
}