#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int k = 0, n = 0, b = 0;
	cin >> k >> n >> b; // камень ножницы бумага

	for (int l = 0; l < k; l++) cout << "P";
	for (int l = 0; l < n; l++) cout << "R";
	for (int l = 0; l < b; l++) cout << "S";
	cout << "\n";
	/* if (k >= n && k >= b) { // контр k - n  n - b  b - k  ||   R — камень, S — ножницы, P — бумага.

	}
	else {

	}
		if (n > b) {
			for (int l = 0; l < k; l++) cout << "P";
			for (int l = 0; l < k; l++) cout << "P";
		}
		else {

		}
	}
	else if (n >= k && n >= b) {
		if (k > b) {

		}
		else {

		}
	}
	else if (b >= n && b >= k) {
		if (n > k) {

		}
		else {

		}
	}

	*/
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