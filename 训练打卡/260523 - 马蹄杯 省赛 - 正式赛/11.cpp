#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    int x; cin >> x;
    cout << (x / 3600) << " " << (x % 3600 / 60) << " " << (x % 60);
    return 0;
}