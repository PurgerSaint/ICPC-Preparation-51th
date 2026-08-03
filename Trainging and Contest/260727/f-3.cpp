#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct State {
    string name, state;
    int id, time;
    State(string s, string a, char c, int d): name(s), state(a), id(c - 'A'), time(d) {}
};
struct rk {
    string name;
    int act;
    vector<int> ac, wa, un;
    rk(string s): name(s), act(0), ac(26, -1), wa(26, 0), un(26, 300) {}
};
struct sub {
    string name;
    int ac, time;
    sub(string n, int a, int b): name(n), ac(a), time(b) {}
};

void solve() {
    int n; cin >> n;
    vector<State> log;
    for (int i = 0; i < n; i++) {
        string a, b; int d; char c;
        cin >> a >> c >> d >> b;
        log.push_back(State(a, b, c, d));
    }
    sort(range(log), [](State& a, State& b){ return a.time < b.time; });
    map<string, rk> r;
    for (State& p: log) {
        string& name = p.name, state = p.state;
        int& i = p.id, time = p.time;
        auto it = r.find(name);
        if (it == r.end()) it = r.emplace(name, name).first;
        rk& rg = it->second;
        if (rg.ac[i] != -1) continue;
        if (state == "Accepted") {
            rg.ac[i] = time;
            rg.act++;
        } else if (state == "Rejected") {
            rg.wa[i]++;
        } else if (rg.un[i] == 300) {
            rg.un[i] = time;
        }
    }
    vector<sub> rank;
    for (auto& [name, g]: r) {
        int time = 0;
        for (int j = 0; j < 26; j++)
            if (g.ac[j] != -1)
                time += g.ac[j] + g.wa[j] * 20;
        rank.push_back(sub(name, g.act, time));
    }

    vector<string> res;
    for (auto& [name, g]: r) {
        int time = 0, cnt = 0;
        for (int j = 0; j < 26; j++) {
            if (g.ac[j] != -1) {
                time += g.ac[j] + g.wa[j] * 20;
            } else if (g.un[j] != 300) {
                cnt++;
                time += g.un[j] + g.wa[j] * 20;
            }
        }
        int act = g.act + cnt;

        bool f = 1;
        for (sub& p: rank) {
            if (p.name == name) continue;
            if ((act == p.ac && time > p.time) || act < p.ac) {
                f = 0;
                break;
            }
        }
        if (f) res.push_back(name);
    }
    sort(range(res));
    for (auto it = res.begin(); it != res.end(); it++)
        cout << *it << (it + 1 != res.end() ? " " : "");
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}
