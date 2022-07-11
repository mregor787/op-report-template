#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w;
            cin >> w;
            d[i][j] = w;
        }
    }
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << d[i][j] << " ";
        cout << endl;
    }
    return 0;
}