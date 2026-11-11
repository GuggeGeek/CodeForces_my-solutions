// 1679B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, q = 0;
	cin >> n >> q;
	vector<long long> st(n, 0);
	long long sum = 0;
	for (int l = 0; l < n; l++) {
		cin >> st[l];
		sum += st[l];
	}

	vector<int> up(n, 0);
	long long upch = 0;
	int times = -1;

	for (int l = 1; l <= q; l++) {
		int a = 0;
		cin >> a;
		if (a == 1) { // 1 элемент
			int ind = 0;
			long long x = 0;
			cin >> ind >> x;

			if (up[ind - 1] > times) { // число меняли позже глобала
				sum += x - st[ind - 1];
			}
			else sum += x - upch;
			st[ind - 1] = x;
			up[ind - 1] = l;
		}
		else {
			long long x = 0;
			cin >> x;
			sum = x * n;
			times = l;
			upch = x;
		}
		cout << sum << "\n";
	}
	

	return 0;
}