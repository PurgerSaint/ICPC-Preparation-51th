#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int solve(){
    vector<ll> mark(32);
    for (int i = 1; i <= 32; i++) {
        cin>>mark[i-1];
    }
    ll cn = mark[0];
    sort(mark.begin(), mark.end(), [](ll& a, ll& b){
        return a > b;
    });
    int rank;
    for (int i = 0; i < 32; i++)
        if (mark[i] == cn) {
            rank = i + 1;
            break;
        }
    // 第1总决赛
    if (rank == 1) return 1;
    // 打不过前1 或 前4中有一个打过的 止步决赛
    if (rank <= 5 && rank > 1) return 2;
    // 打不过前2 或 前8中有一个打过的 止步4强
    if (rank <= 19 && rank > 5) return 4;
    // 打不过前4 或 前16中有1个打过的 止步8强
    if (rank <= 15 && rank > 4) return 8;
    // 最好情况：32队中有两队打过进16强
    if (rank <= 30) return 16;
    return 32;
}
int main(){
    IOS;
    int t; cin>>t;
    while(t--) {
        cout << solve() << (t == 0 ? "" : "\n");
    }
    return 0;
}
