#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t = 0;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	for (int l = 0; l < t; l++) { // Колво тестов
		int n = 0;
		cin >> n;
		int mini = 0; // массив с минимальным second , в него и полетит весь мусор
		long long minis = 1e18;
		vector<pair<long long, long long>> val(n + 1, pair(1e18, 1e18));
		for (int j = 1; j <= n; j++) { // кол-во  массивов
			int m = 0;
			cin >> m;
			for (int k = 0; k < m; k++) { // значения чисел
				long long a = 0;
				cin >> a;
				if (a < val[j].first) {
					val[j].second = val[j].first;
					val[j].first = a;
				}
				else if (a < val[j].second) val[j].second = a;
			}
			minis = min(minis, val[j].first);
			if (val[j].second < val[mini].second) {
				mini = j;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (j == mini) continue;
			minis += val[j].second;
		}
		cout << minis << "\n";
	}

	return 0;
}