#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
vector<vector<pair<ll, ll>>> mp;
ll l, s, t;

struct State {
    ll u, cnt, cost;
    State(ll a, ll b, ll c): u(a), cnt(b), cost(c) {}
    bool operator<(const State& other) const {
        return cnt < other.cnt;
    }
};

void solve() {
    ll n = mp.size() - 1;
    priority_queue<State> pq;
    pq.push(State(1, 0, 0));

    set<ll> note;

    while (!pq.empty()) {
        State p = pq.top(); pq.pop();

        if (p.cnt == l && (p.cost >= s && p.cost <= t)) {
            note.insert(p.u);
            // continue;
        }
        for (pair<ll, ll>& q: mp[p.u]) {
            ll cost = q.second + p.cost;
            ll cnt = p.cnt + 1;
            if (cost <= t && cnt <= l)
                pq.push(State(q.first, cnt, cost));
        }
    }

    size_t size = note.size(), cnt = 0;
    for (const ll& t: note) {
        cout << t;
        cnt++;
        cout << (cnt != size ? " " : "");
    }
}

int main() {
    ios;
    ll n, m; cin >> n >> m >> l >> s >> t;
    mp = vector<vector<pair<ll, ll>>>(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, c; cin >> u >> v >> c;
        mp[u].push_back({v, c});
    }
    solve();
    return 0;
}