#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
const ll MOD = 998244353;

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll n) {
    return power(n, MOD - 2);
}

struct MaxOccur {
    int m1 = 0, m2 = 0, c1 = 0;
    void update(int x) {
        if (x > m1) {
            m2 = m1;
            m1 = x;
            c1 = 1;
        } else if (x == m1) {
            c1++;
        } else if (x > m2) {
            m2 = x;
        }
    }
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    map<int, MaxOccur> prime_map;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int temp = a[i];
        for (int j = 2; j * j <= temp; j++) {
            if (temp % j == 0) {
                int cnt = 0;
                while (temp % j == 0) {
                    temp /= j;
                    cnt++;
                }
                prime_map[j].update(cnt);
            }
        }
        if (temp > 1) prime_map[temp].update(1);
    }

    ll total_lcm = 1;
    for (auto const& [p, info]: prime_map) {
        total_lcm = total_lcm * power(p, info.m1) % MOD;
    }

    for (int i = 0; i < n; i++) {
        ll current_res = total_lcm;
        int temp = a[i];

        for (int j = 2; j * j <= temp; j++) {
            if (temp % j == 0) {
                int cnt = 0;
                while (temp % j == 0) {
                    temp /= j;
                    cnt++;
                }
                if (cnt == prime_map[j].m1 && prime_map[j].c1 == 1) {
                    current_res = current_res * inv(power(j, prime_map[j].m1)) % MOD;
                    current_res = current_res * power(j, prime_map[j].m2) % MOD;
                }
            }
        }
        if (temp > 1) {
            if (prime_map[temp].m1 == 1 && prime_map[temp].c1 == 1) {
                current_res = current_res * inv(power(temp, prime_map[temp].m1)) % MOD;
                current_res = current_res * power(temp, prime_map[temp].m2) % MOD;
            }
        }
        
        cout << current_res << (i == n - 1 ? "" : " ");
    }
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        cout << (t != 0 ? "\n" : "");
    }
    return 0;
}