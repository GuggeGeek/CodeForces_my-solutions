// 1195C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> st1(n, 0), st2(n, 0);
	vector<vector<long long>> mat(3, vector<long long>(n + 1, 0));
	mat[0][0] = 0, mat[1][0] = 0, mat[2][0] = 0;

	for (int l = 0; l < n; l++) cin >> st1[l];
	for (int l = 0; l < n; l++) cin >> st2[l];

	for (int l = 1; l <= n; l++) {
		mat[2][l] = max(mat[2][l - 1], max(mat[1][l - 1], mat[0][l - 1]));

		mat[0][l] = st1[l - 1] + (max(mat[1][l - 1], mat[2][l - 1]));

		mat[1][l] = st2[l - 1] + (max(mat[0][l - 1], mat[2][l - 1]));
	}

	cout << max(mat[0][n], max(mat[1][n], mat[2][n]));

	return 0;
}