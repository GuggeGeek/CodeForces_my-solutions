#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
	int n = 0, oper = 0;
	cin >> n;
	vector<long long> st(n, 0);
	long long media = 0, price = 0;
	for (int l = 0; l < n; l++) cin >> st[l];
	sort(st.begin(), st.end());

	if (n % 2 == 1) media = st[n / 2];
	else media = (st[n / 2] + st[n / 2 - 1]) / 2;

	long long it = lower_bound(st.begin(), st.end(), media) - st.begin(); // медиана индекс
	if (st[0] < 0) {
		if (media < 0) oper += abs(st[0]) - abs(media);
		else oper += media - st[0];
	}
	else oper += media - st[0];

	for (int l = 0; l < it; l++) {
		if (st[l] < 0) {
			if (media < 0) price += abs(st[l]) - abs(media);
			else price += media - st[l];
		}
		else price += media - st[l];
	}

	if (media < 0) {
		if (st[n - 1] < 0) oper += abs(media) - abs(st[n - 1]);
		else oper += st[n - 1] - media;
	}
	else oper += st[n - 1] - media;

	while (it < n) {
		if (media < 0) {
			if (st[it] < 0) price += abs(media) - abs(st[it]);
			else price += st[it] - media;
		}
		else price += st[it] - media;
		it++;
	}

	cout << price << " " << oper << "\n";
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