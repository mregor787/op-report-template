#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    const int64_t INF = 1e8;
    vector<int64_t> dp(n + 1, INF);
    dp[1] = 0;
    int i = 2;
    while (i <= n) {
        int64_t min_dp = INF;
        if (i % 2 == 0)
            if (dp[i / 2] < min_dp)
                min_dp = dp[i / 2];
        if (i % 3 == 0)
            if (dp[i / 3] < min_dp)
                min_dp = dp[i / 3];
        if (dp[i - 1] < min_dp)
            min_dp = dp[i - 1];
        dp[i] = min_dp + i;
        ++i;
    }
    cout << dp[n];
    return 0;
}