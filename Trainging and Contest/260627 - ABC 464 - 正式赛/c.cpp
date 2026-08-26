#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
struct bird_state {
    int af, be;
    int d;
    int i;
    bird_state(int a, int b, int c, int e): af(a), be(b), d(c), i(e) {}
};
int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<bird_state> bird;
    vector<int> color_cnt(n + 1, 0);
    set<int> color_num;
    for (int i = 1; i <= n; i++) {
        int a, b, c; cin >> a >> b >> c;
        bird.push_back(bird_state(a, c, b, i));
        color_cnt[a]++;
        color_num.insert(a);
    }
    sort(bird.begin(), bird.end(), [](auto& a, auto& b){
        return a.d > b.d;
    });
    int bird_cnt = color_num.size();
    vector<int> day(m + 1, 0);
    day[0] = bird_cnt;
    for (int i = 1; i <= m; i++) {
        if (!bird.empty()) {
            if (bird.back().d > i) {
                day[i] = day[i - 1];
                continue;
            }
            while (!bird.empty() && bird.back().d == i) {
                bird_state& each = bird.back();
                color_cnt[each.af]--;
                if (color_cnt[each.be] == 0 && color_cnt[each.af] > 0) {
                    // cout << "add i:" << each.i << " day:" << i << "\n";
                    bird_cnt++;
                }
                if (color_cnt[each.be] > 0 && color_cnt[each.af] == 0) {
                    // cout << "les i:" << each.i << " day:" << i << "\n";
                    bird_cnt--;
                }
                color_cnt[each.be]++;
                bird.pop_back();
            }
            day[i] = bird_cnt;
        } else day[i] = day[i - 1];
    }
    for (int i = 1; i <= m; i++)
        cout << day[i] << (i < m ? "\n" : "");
    return 0;
}