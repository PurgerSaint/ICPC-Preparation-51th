#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define ll long long

int main() {
    ios;
    ll n; cin >> n;
    map<ll, vector<ll>> pos;
    ll ma = 0, mc = 0;
    for (ll i = 0; i < n; i++) {
        ll val; cin >> val;
        pos[val].push_back(i);
    }
    ll cnt = 0;
    for (const pair<ll, vector<ll>>& p : pos) {
        const ll& val = p.first;
        const vector<ll>& j_num = p.second;
        if (val % 5 != 0) continue;
        ll x = val / 5;
        ll v_i = 7 * x, k_i = 3 * x;

        if (pos.count(v_i) && pos.count(k_i)) {
            const vector<ll>& i_num = pos[v_i];
            const vector<ll>& k_num = pos[k_i];

            for (const ll& j: j_num) {
                ll i_left = lower_bound(i_num.begin(), i_num.end(), j) - i_num.begin();
                ll k_left = lower_bound(k_num.begin(), k_num.end(), j) - k_num.begin();
                cnt += i_left * k_left;

                ll i_right = i_num.end() - upper_bound(i_num.begin(), i_num.end(), j);
                ll k_right = k_num.end() - upper_bound(k_num.begin(), k_num.end(), j);
                cnt += i_right * k_right;
            }
        }
    }
    cout << cnt;
    return 0;
}

/*
    给与一个长度为N的序列A = (A_1, A_2, ... , A_N)
    寻找满足以下条件的整数三元组(i, j, k)数量：
    1. 1 <= i,j,k <= N
    2. A_i : A_j : A_k = 7 : 5 : 3
    3. min(i, j, k) = j or max(i, j, k) = j
    (1 <= N <= 3*1e5, 1 <= A_i <= 1e9)
*/
// 为什么我这样不行呢？光样例都无法通过