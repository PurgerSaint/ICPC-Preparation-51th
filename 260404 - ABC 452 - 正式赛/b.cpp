#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int h, w; cin >> h >> w;
    for (int i = 0; i < w; i++)
        cout << '#';
    cout << "\n";
    for (int i = 1; i <= h - 2; i++) {
        cout << '#';
        for (int j = 1; j < w - 1; j++)
            cout << '.';
        cout << '#' << "\n";
    }
    for (int i = 0; i < w; i++)
        cout << '#';
    return 0;
}