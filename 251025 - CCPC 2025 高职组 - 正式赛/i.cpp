#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
int main() {
    IOS;
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    bool a = false, b = false;

    auto done = [&](char c) -> void {
        if (c == 'C') a = true;
        else b = true;
    };
    auto check = [&](char c, int x, int y) -> void {
        int t = 1;
        // 上
        for (int i = 1; i < 5; i++) {
            if (x - i < 0) break;
            if (s[x - i][y] != c) break;
            else t++;
        }
        if (t == 5) {
            done(c);
            return;
        }

        t = 1;
        // 下
        for (int i = 1; i < 5; i++) {
            if (x + i >= n) break;
            if (s[x + i][y] != c) break;
            else t++;
        }
        if (t == 5) {
            done(c);
            return;
        }

        t = 1;
        // 左
        for (int i = 1; i < 5; i++) {
            if (y - i < 0) break;
            if (s[x][y - i] != c) break;
            else t++;
        }
        if (t == 5) {
            done(c);
            return;
        }

        t = 1;
        // 右
        for (int i = 1; i < 5; i++) {
            if (y + i >= n) break;
            if (s[x][y + i] != c) break;
            else t++;
        }
        if (t == 5) {
            done(c);
            return;
        }

        t = 1;
        // 左上
        for (int i = 1; i < 5; i++) {
            if (x - i < 0 || y - i < 0) break;
            if (s[x - i][y - i] != c) break;
            else t++;
        }
        if (t == 5) {
            done(c);
            return;
        }

        t = 1;
        // 右下
        for (int i = 1; i < 5; i++) {
            if (x + i >= n || y + i >= n) break;
            if (s[x + i][y + i] != c) break;
            else t++;
        }
        if (t == 5) {
            done(c);
            return;
        }

        t = 1;
        // 左下
        for (int i = 1; i < 5; i++) {
            if (x + i >= n || y - i < 0) break;
            if (s[x + i][y - i] != c) break;
            else t++;
        }
        if (t == 5) {
            done(c);
            return;
        }

        t = 1;
        // 右上
        for (int i = 1; i < 5; i++) {
            if (x - i < 0 || y + i >= n) break;
            if (s[x - i][y + i] != c) break;
            else t++;
        }
        if (t == 5) {
            done(c);
            return;
        }
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'C' && !a) check(s[i][j], i, j);
            else if (s[i][j] == 'Q' && !b) check(s[i][j], i, j);
        }
    if (!a && !b) cout << "No winner till now";
    else if (a && b) cout  << "Too late to know who the winner is";
    else if (a) cout << "The winner is little C";
    else cout << "The winner is little Q";
    return 0;
}