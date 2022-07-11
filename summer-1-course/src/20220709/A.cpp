#include <bits/stdc++.h>

using namespace std;

vector<int> z_func(const string &s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] >= r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for (int elem : z_func(s))
        cout << elem << " ";
    return 0;
}