#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
const ll NEG_INF = numeric_limits<ll>::lowest() / 4;

int main() {
    ios;
    int n, k; cin >> n >> k;
    ll sum = 0;
    vector<ll> gain(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll a, b; cin >> a >> b;
        sum += a;
        gain[i] = b - a;
    }
    vector<ll> dp0(n + 1, NEG_INF), dp1(n + 1, NEG_INF);
    dp0[0] = 0;

    for (int i = 1; i <= n; i++) {
        vector<ll> next0(k + 1, NEG_INF), next1(k + 1, NEG_INF);

        for (int j = 0; j <= k; j++) {
            next0[j] = max(dp0[j], dp1[j]);
            if (dp1[j] != NEG_INF)
                next1[j] = max(next1[j], dp1[j] + gain[i]);
            if (j >= 1 && dp0[j - 1] != NEG_INF)
                next1[j] = max(next1[j], dp0[j - 1] + gain[i]);
        }
        dp0.swap(next0);
        dp1.swap(next1);
    }
    
    cout << sum + max(*max_element(dp0.begin(), dp0.end()), *max_element(dp1.begin(), dp1.end()));
    return 0;
}
