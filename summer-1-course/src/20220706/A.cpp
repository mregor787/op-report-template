#include <bits/stdc++.h>

using namespace std;


void fft(vector<complex<double>> &a) {
    int n = pow(2, ceil(log2(a.size()))), n_old = a.size();
    for (int i = 0; i < n - n_old; ++i)
        a.push_back(complex<double>(0));
    if (n == 1)
        return;
    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (int i = 0, j = 0; j < n; ++i, j += 2) {
        a0[i] = a[j];
        a1[i] = a[j + 1];
    }
    fft(a0);
    fft(a1);
    double phi = 2.0 * acos(-1) / n;
    complex<double> w(1), wn(cos(phi), sin(phi));
    for (int i = 0; i < n / 2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[n / 2 + i] = a0[i] - w * a1[i];
        w *= wn;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<complex<double>> vc;
    for (int i = 0; i < n; ++i) {
        complex<double> c;
        cin >> c;
        vc.push_back(c);
    }
    fft(vc);
    stringstream ss;
    ss.setf(ios::fixed);
    ss.precision(10);
    for (auto c: vc)
        ss << c.real() << " " << c.imag() << '\n';
    cout << ss.str();
    return 0;
}