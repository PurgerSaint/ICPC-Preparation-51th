#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int a, b; cin >> a >> b;
    int t = 6 - max(a, b) + 1, g = 6;
    if (t == 4) cout << "2/3";
    else if (t == 3) cout << "1/2";
    else if (t == 2) cout << "1/3";
    else if (t == 6) cout << "1/1";
    else cout << t << "/" << g; 
    return 0;
}