#include <bits/stdc++.h>

using namespace std;


class Database {
private:
    map<string, pair<string, bool>> data;
public:
    string register_user(string login, string password) {
        if (data.find(login) != data.end())
            return "login already in use";
        data[login] = make_pair(password, false);
        return "account created";
    }
    string login_user(string login, string password) {
        if (data.find(login) == data.end())
            return "wrong account info";
        if (data[login].first != password)
            return "wrong account info";
        if (data[login].second)
            return "already logged in";
        data[login].second = true;
        return "logged in";
    }
    string logout_user(string login) {
        if (data.find(login) == data.end())
            return "incorrect operation";
        if (!data[login].second)
            return "incorrect operation";
        data[login].second = false;
        return "logged out";
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Database db;
    string cmd;
    while (cin >> cmd) {
        string login;
        cin >> login;
        if (cmd == "logout") {
            cout << db.logout_user(login) << '\n';
            continue;
        }
        string password;
        cin >> password;
        if (cmd == "register")
            cout << db.register_user(login, password) << '\n';
        else if (cmd == "login")
            cout << db.login_user(login, password) << '\n';
    }
    return 0;
}