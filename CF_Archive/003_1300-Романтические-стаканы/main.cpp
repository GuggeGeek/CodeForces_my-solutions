// 1915E
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int t = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	for (int l = 0; l < t; l++) { // тестов && массивов
		int n = 0;
		cin >> n;
		set<long long> up;
		long long pref = 0;
		up.insert(0);
		bool flage = false;
		for (int j = 0; j < n; j++) { // стаканов
			long long a = 0;
			cin >> a;
			if (flage) continue;
			if (j % 2 == 0) pref += a;
			else pref -= a;
			if (up.contains(pref)) {
				flage = true;
			}
			else up.insert(pref);
		}
		if (!flage) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}

	return 0;
}