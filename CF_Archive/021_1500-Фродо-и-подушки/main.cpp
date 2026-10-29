// 760B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool chek(long long m, long long k, long long mid, long long cnt) {
	long long maxil = max(1LL, mid - (k - 1));
	long long maxir = max(1LL, mid - cnt);
	long long ans = (maxil + mid) * (mid - maxil + 1) / 2 + (maxir + mid) * (mid - maxir + 1) / 2 - mid;
	if (k > mid) ans += (k - mid);
	if (cnt > mid) ans += cnt - (mid - 1);
	if (ans > m) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n = 0, m = 0, k = 0; // хоббиты подушки фродо
	cin >> n >> m >> k;
	long long l = 1, r = 1e9 + 7, ans = 1;
	long long cnt = n - k;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (chek(m , k, mid, cnt)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
			ans = mid;
		}
	}
	cout << ans;

	return 0;
}