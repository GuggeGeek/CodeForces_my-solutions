#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve() {
	int k = 0, n = 0, b = 0;
	cin >> k >> n >> b; // камень ножницы бумага
	int sum = n + b + k;
	if (k >= n && k >= b) { // контр k - n  n - b  b - k  ||   R — камень, S — ножницы, P — бумага.
		cout << string(sum, 'P') << "\n";
	}
	else if (n >= k && n >= b) {
		cout << string(sum, 'R') << "\n";
	}
	else {
		cout << string(sum, 'S') << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) {
		solve();
	}

	return 0;
}