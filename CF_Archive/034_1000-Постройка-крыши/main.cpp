// 1632B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	n--;
	int log = __lg(n);
	for (int l = n; l >= (1 << log); l--) {
		cout << l << " ";
	}
	cout << 0 << " ";
	for (int l = (1 << log) - 1; l > 0; l--) {
		cout << l << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0;l < t; l++) {
		solve();
	}

	return 0;
}