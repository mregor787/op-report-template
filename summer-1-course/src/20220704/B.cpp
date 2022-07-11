#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
int64_t INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> events;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, 2});
    }
    sort(events.begin(), events.end());
    int64_t lp = -INF, cnt = 0, ans = 0;
    for (pii elem: events) {
        int xi = elem.first, event = elem.second;
        if (event == 1)
            ++cnt;
        else
            --cnt;
        if (!cnt) {
            ans += xi - lp;
            lp = -INF;
        }
        else if (lp == -INF)
            lp = xi;
    }
    cout << ans;
    return 0;
}