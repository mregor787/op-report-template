#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<int>>;
const int INF = 1e9;

vector<int> bfs(int start, const graph &g) {
    int n = g.size();
    vector<int> d(n, INF);
    d[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int d: bfs(k - 1, g))
        if (d == INF)
            cout << "-1 ";
        else
            cout << d << " ";
    return 0;
}