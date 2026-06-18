#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
struct cmp {
    bool operator()(pair<ll, ll>& a, pair<ll, ll>& b) {
        return a.first < b.first;
    }
};
struct ques{
    int i;
    ll t;
    ll mx;
    ques(int a, ll b): i(a), t(b), mx(0 * 1LL) {}
};
int main() {
    ios;
    int n; cin >> n;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    for (int i = 0; i < n; i++) {
        ll h, l; cin >> h >> l;
        pq.push({h, l});
    }
    int q; cin >> q;
    vector<ques> que;
    for (int i = 0; i < q; i++) {
        ll t; cin >> t;
        que.push_back(ques(i, t));
    }
    sort(que.begin(), que.end(), [](ques& a, ques& b) {
        return a.t < b.t;
    });
    for (ques& t: que) {
        // vector<pair<ll, ll>> bk;
        while (!pq.empty() && pq.top().second <= t.t) {
            // bk.push_back(pq.top());
            // cout << "t:" << t.t << " " << "less h:" << pq.top().first << " l:" << pq.top().second << "\n";
            pq.pop();
        }
        if (!pq.empty()) {
            t.mx = pq.top().first;
        }
    }
    sort(que.begin(), que.end(), [](ques& a, ques& b) {
        return a.i < b.i;
    });
    for (int i = 0; i < q; i++) {
        cout << que[i].mx << (i < q - 1 ? "\n" : "");
    }
    return 0;
}