#include <bits/stdc++.h>

using namespace std;

int get_dp(vector<vector<int>> &dp, vector<vector<int>> &field, int i, int j, int n, int m) {
    vector<pair<int, int>> moves{{-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};
    int res = -1;
    for (int k = 0; k < 4; ++k) {
        pair<int, int> move = moves[k];
        int res_i = move.first + i, res_j = move.second + j;
        if (res_i >= 0 && res_i < n && res_j >= 0 && res_j < m) {
            if (dp[res_i][res_j] == -1)
                continue;
            res = max(res, dp[res_i][res_j]);
        }
    }
    return res != -1 ? res + field[i][j] : -1;
}

vector<pair<int, int>> get_indexes(int len, int n, int m) {
    vector<pair<int, int>> res;
    for (int i = 0; i <= len; ++i) {
        int x = i, y = len - i;
        if (x < n && y < m)
            res.push_back({x, y});
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> field(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> field[i][j];
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = field[0][0];
    int max_gold = dp[0][0];
    for (int k = 1; k < n + m - 1; ++k) {
        for (auto ind: get_indexes(k, n, m)) {
            int i = ind.first, j = ind.second;
            dp[i][j] = get_dp(dp, field, i, j, n, m);
            max_gold = max(max_gold, dp[i][j]);
        }
    }
    cout << max_gold << '\n';
    return 0;
}