#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> banknotes{5000, 1000, 500, 200, 100};
        vector<int> bn_nums(5);
        for (int j = 0; j < 5; ++j) {
            bn_nums[j] = n / banknotes[j];
            n %= banknotes[j];
        }
        for (int j = 4; j >= 0; --j)
            cout << bn_nums[j] << " ";
        cout << '\n';
    }
    return 0;
}