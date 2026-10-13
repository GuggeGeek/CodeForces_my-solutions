//1849B
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++) { // тестов
		int n = 0;
		long long k = 0;
		cin >> n >> k;
		vector<pair<long long, int>> mon(n + 1);
		for (int j = 0; j < n; j++) {
			long long a = 0;
			cin >> a;
			long long rem = a % k;
			if (rem == 0) rem = k;
			
			mon[j] = pair(-rem, j + 1);
		}

		sort(mon.begin(), mon.end());

		
		for (int j = 0; j < n; j++) {
			cout << mon[j].second << " ";
		}
		cout << "\n";
	}

	return 0;
}