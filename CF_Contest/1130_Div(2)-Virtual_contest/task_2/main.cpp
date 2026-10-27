#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) {
		int n = 0;
		cin >> n;
		int tota = 0, totb = 0, isk = 0;
		vector<pair<int, int>> frog(n);
		for (int i = 0; i < n; i++) {
			char a1, b1;
			int a, b;
			cin >> a1 >> b1;
			if (a1 == 'f') {
				a = 1;
				tota++;
			}
			else a = 0;
			if (b1 == 'f') {
				b = 1;
				totb++;
			}
			else b = 0;
			if (a == 1 && b == 0 || a == 0 && b == 1) isk++;
			frog[i] = pair(a, b);
		}
		if (isk % 2 == 1) cout << 1 << "\n";
		else cout << 0 << "\n";

	}

	return 0;
}