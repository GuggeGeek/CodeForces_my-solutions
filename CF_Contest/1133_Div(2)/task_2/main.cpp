#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n = 0;
	cin >> n;
	cout << "? 1 " << n << endl;
	cout.flush();
	int one = 0, two = 0;
	cin >> one;
	if (one == n || one == 0) {
		cout << "! NO" << endl;
		cout.flush();
	}
	else {
		if (one == 1) {
			cout << "? 2 " << n << endl;
			cout.flush();
			cin >> two;
			if (two == 0) {
				cout << "! NO" << endl;
				cout.flush();
				return;
			}
		}
		cout << "? 1 " << one << endl;
		cout.flush();
		cin >> two;
		if (two == one) {
			cout << "! NO" << endl;
			cout.flush();
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