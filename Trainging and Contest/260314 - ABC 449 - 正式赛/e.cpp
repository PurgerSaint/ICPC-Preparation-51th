#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

struct nm {
    ll num;
    ll cnt;
    nm(ll c, ll t): cnt(c), num(t) {}
    void inc() {
        cnt++;
    }
    bool operator<(const nm& other) const {
        return other.num == num ? cnt < other.cnt : num < other.num;
    }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<ll> e(n);
    vector<ll> cnt(m + 1, 0);
    for (ll& t: e) {
        cin >> t;
        cnt[t]++;
    }
    ll q, mq = INT_MAX; cin >> q;
    vector<ll> qt;
    for (ll& t: qt) {
        cin >> t;
        mq = max(mq, t);
    }
    if (mq <= n) {
        for (int i = 0; i < qt.size(); i++)
            cout << e[qt[i]] << (i != qt.size() - 1 ? "\n" : "");
        return 0;
    }

    priority_queue<nm> pq;
    unordered_map<ll, nm> hash;
    for (int i = 1; i <= m; i++) {
        hash[i] = nm(i, cnt[i]);
        pq.push(hash[i]);
    }

    while (mq--) {
        const ll& t = pq.top().num;
        e.push_back(t);
        hash[t].cnt++;
    }
    return 0;
}
