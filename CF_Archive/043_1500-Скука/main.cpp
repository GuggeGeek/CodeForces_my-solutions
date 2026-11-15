// 455A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> act(100000 + 1, 0);
	for (int l = 0; l < n; l++) {
		int a = 0;
		cin >> a;
		act[a] += a;
	}

	vector<vector<long long>> mat(2, vector<long long>(100000 + 1, 0));

	for (int l = 1; l <= 100000; l++) {
		mat[0][l] = mat[1][l - 1] + act[l];
		mat[1][l] = max(mat[0][l - 1], mat[1][l - 1]);
	}

	cout << max(mat[0][100000], mat[1][100000]);

	return 0;
}