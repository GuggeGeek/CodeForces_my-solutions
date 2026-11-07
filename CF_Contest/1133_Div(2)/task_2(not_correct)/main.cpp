#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	cout << "? 1 " << n << endl;
	cout.flush();
	int one = 0;
	cin >> one;
	if (one == n || one == 0) {
		cout << "! NO" << endl;
		cout.flush();
	}
	else {
		cout << "? 1 1" << endl;
		cout.flush();
		cin >> one;
		if (one == 1) {
			cout << "? " << n << " " << n << endl;
			cout.flush();
			cin >> one;
			if (one == 1) {
				cout << "! YES" << endl;
				cout.flush();
			}
			else {
				cout << "! NO" << endl;
				cout.flush();
			}
		}
		else {
			cout << "! YES" << endl;
			cout.flush();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.flush();

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) {
		solve();
	}

	return 0;
}