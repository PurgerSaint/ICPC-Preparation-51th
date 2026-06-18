#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
struct State {
    string name;
    char t;
    int time;
    string state;
    State(string s, char c, int ti, string st) : name(s), time(ti), t(c), state(st) {}
};
struct rk {
    string name;
    int act;
    vector<int> ac;
    vector<int> wa;
    vector<int> unt;
    rk(string s) : name(s), act(0), ac(26, -1), unt(26, INT_MAX), wa(26, 0) {}
};
struct sub {
    string name;
    int ac;
    int time;
    sub(string n, int a, int t) : name(n), ac(a), time(t) {}
};
void solve(){
    int k; cin>>k;
    /* 先输入全部日志数据 */
    vector<string> list;
    set<string> l;
    vector<State> log;
    for (int i = 0; i < k; i++) {
        string name, state;
        char t; int time;
        cin>>name>>t>>time>>state;
        log.push_back(State(name, t, time, state));
        if (l.find(name) != l.end()) continue;
        l.insert(name);
        list.push_back(name);
    }
    sort(log.begin(), log.end(), [](State& a, State& b){
        return a.time < b.time;
    });

    /* 再分析所有日志数据 */
    vector<rk> r;
    unordered_map<string, int> hash;
    for (State& p : log) {
        string& name = p.name, state = p.state;
        char t = p.t; int time = p.time;

        if (hash.find(name) == hash.end()) {
            r.push_back(rk(name));
            hash[name] = r.size() - 1;
        }
        rk& g = r[hash[name]];

        int id = t - 'A';
        if (g.ac[id] != -1) continue;

        if (state == "Accepted") {
            g.ac[id] = time;
            g.act++;
        } else if (state == "Rejected") {
            g.wa[id]++;
        } else if (g.unt[id] == INT_MAX) {
            // 只记录第一次unkonw时间
            g.unt[id] = time;
        } 
    }

    // 假设当前对，其余未知全错
    // 提取每一个可能为第一的
    vector<sub> rank;
    int size = list.size();
    for (int i = 0; i < size; i++) {
        rk& g = r[hash[list[i]]];
        int time = 0;
        for (int j = 0; j < 26; j++) {
            if (g.ac[j] != -1)
                time += g.ac[j] + g.wa[j] * 20;
        }
        rank.push_back(sub(g.name, g.act, time));
    }
    auto better = [](sub& a, sub& b){
        if (a.ac == b.ac) return a.time < b.time;
        return a.ac > b.ac;
    };

    vector<string> res;
    for (int i = 0; i < size; i++) {
        rk& g = r[hash[list[i]]];
        int time = 0, cnt = 0;
        for (int j = 0; j < 26; j++) {
            if (g.ac[j] != -1)
                time += g.ac[j] + g.wa[j] * 20;
            else if (g.unt[j] != INT_MAX) {
                cnt++;
                time += g.unt[j] + g.wa[j] * 20;
            }
        }
        sub t = sub(g.name, g.act + cnt, time);

        bool flag = false;
        for (sub& p : rank) {
            if (p.name == t.name) continue;
            if (better(p, t)) {
                flag = true;
                break;
            }
        }
        if (!flag) res.push_back(g.name);
    }

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<(i != res.size() - 1 ? " " : "");
}
int main(){
    IOS;
    int t; cin>>t;
    while(t--) {
        solve();
        cout<< (t == 0 ? "" : "\n");
    }
    return 0;
}