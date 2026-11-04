#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int l = 0, r = 0, sum = 0;
	cin >> l >> r;
	for (int i = 0; i <= abs(r - l); i++) {
		sum += l + i;
	}

	if (sum <= r && sum >= l) {
		cout << 0 << "\n";
		return;
	}

	int ch = 0;
	if (sum > r) {
		while (abs(r - l) > 0) {
			sum -= r;
			r--;
			ch++;
			if (sum <= r && sum >= l) {
				cout << ch << "\n";
				return;
			}
		}
		cout << ch << "\n";
	}
	else {
		while (abs(r - l) > 0) {
			sum -= l;
			l++;
			ch++;
			if (sum <= r && sum >= l) {
				cout << ch << "\n";
				return;
			}
		}
		cout << ch << "\n";
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