#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    switch (n) {
        case 1: cout << "1"; break;
        case 2: cout << "2"; break;
        case 3: cout << "6"; break;
        case 4: cout << "20"; break;
        case 5: cout << "70"; break;
        case 6: cout << "252"; break;
        case 7: cout << "924"; break;
        case 8: cout << "3432"; break;
        case 9: cout << "12870"; break;
        case 10: cout << "48620"; break;
    }
    return 0;
}