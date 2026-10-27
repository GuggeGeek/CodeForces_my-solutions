#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool solve(vector<long long> a, long long mid, long long x) {
	long long ans = 0;
	int j = 0;
	long long mini = a[j + 1] - a[j];
	if (a.size() > 1) while (mini > mid) {
		a.insert(a.begin() + j, a[j + 1] + (a[j + 1] - a[j]) / 2);
		mini = a[j + 1] - a[j];
		x--;
		if (x < 0) return false;
	}
	for (int l = 1; l < a.size() - 1; l++) {
		mini = min(a[l] - a[l - 1], a[l + 1] - a[l]);
		if (mini == a[l] - a[l - 1]) { // шаг назад
			while (mini > mid) {
				a[l - 1] = a[l - 1] + (a[l] - a[l - 1]) / 2; // мб +1
				mini = a[l] - a[l - 1];
				x--;
				if (x < 0) return false;
			}
		}
		else { // шаг вперёд
			while (mini > mid) {
				a.insert(a.begin() + l, a[l + 1] + (a[l + 1] - a[l]) / 2);
				mini = a[l + 1] - a[l];
				x--;
				if (x < 0) return false;
			}
		}
	}
	mini = a[j] - a[j - 1];
	j = a.size() - 1;
	while (mini > mid) {
		a[j - 1] = a[j - 1] + (a[j] - a[j - 1]) / 2; // мб +1
		mini = a[j] - a[j - 1];
		x--;
		if (x < 0) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0, x = 0;
		cin >> n >> x;
		vector<long long> a(n, 0);
		for (int l = 0; l < n; l++) {
			cin >> a[l];
		}

		long long l = 0, r = 1e9 + 7, ans = 0;
		while (l <= r) {
			long long mid = l + (r - l) / 2;
			if (solve(a, mid, x)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << "\n";
	}

	return 0;
}