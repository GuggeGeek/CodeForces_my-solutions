#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Подсчет k-го по величине префиксного MEX за O(N)
int getk(const vector<int>& a, int k) {
    int n = a.size();
    vector<int> f(n);
    vector<bool> vis(n + 1, false);
    int curmex = 0;

    for (int i = 0; i < n; ++i) {
        vis[a[i]] = true;
        while (vis[curmex]) {
            curmex++;
        }
        f[i] = curmex;
    }

    sort(f.rbegin(), f.rend());
    return f[k - 1];
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int orig_score = getk(a, k);
    int best_score = orig_score;
    int best_i = -1, best_j = -1;

    // Перебираем все возможные пары (i, j)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(a[i], a[j]);
            int cur_score = getk(a, k);
            if (cur_score > best_score) {
                best_score = cur_score;
                best_i = i + 1; // переводим в 1-индексацию
                best_j = j + 1;
            }
            swap(a[i], a[j]); // откат
        }
    }

    if (best_i == -1) {
        cout << -1 << "\n";
    }
    else {
        cout << best_i << " " << best_j << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}