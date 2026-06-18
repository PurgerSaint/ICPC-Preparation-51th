#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n; cin >> n;
    vector<int> cnt(5, 0);
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        cnt[d]++;
    }
    int ans = cnt[4];
    if (cnt[2]) {
        ans += cnt[2] / 2;
        if (cnt[2] % 2) {
            if (cnt[1]) {
                cnt[1]--;
                if (cnt[1]) cnt[1]--;
            }
            ans++;
        }
    }
    if (cnt[1] || cnt[3]) {
        if (cnt[1] && !cnt[3]) {
            ans += cnt[1] / 4 + (cnt[1] % 4 ? 1 : 0);
        } else if (cnt[3] && !cnt[1]) {
            ans += cnt[3];
        } else {
            ans += min(cnt[3], cnt[1]);
            if (cnt[3] > cnt[1])
                ans += cnt[3] - cnt[1];
            else if (cnt[1] > cnt[3]) {
                int d = cnt[1] - cnt[3];
                ans += d / 4 + (d % 4 ? 1 : 0);
            }
        }
    }
    cout << ans;
    return 0;
}