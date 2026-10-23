// 1225B2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> num(2000001, 0); // индекс - знач числа || ячейка - сколько раз встретилось
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0, k = 0, d = 0; // кол-во дней || кол-во сериалов || кол-во непрерывного сеанса
		int kol = 0, ans = 1e9; // подписок в диапазоне || ответ 
		cin >> n >> k >> d;
		vector<int> st(n + 1, 0); // изначальный ряд
		for (int l = 1; l <= n; l++) {
			cin >> st[l];
			if (l <= d) {
				num[st[l]]++;
				if(num[st[l]] == 1) kol++;
			}
		}


		ans = kol;
		int l = 2, r = d + 1;
		while (r <= n) {
			num[st[l - 1]]--;
			if (num[st[l - 1]] == 0) kol--;


			num[st[r]]++;
			if (num[st[r]] == 1) kol++;

			ans = min(ans, kol);
			l++; r++;
		}

		for (int j = 1; j <= n; j++) num[st[j]] = 0;
		cout << ans << "\n";
	}

	return 0;
}