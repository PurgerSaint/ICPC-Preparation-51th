#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int missingMultiple(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    vector<int> a;
    int ans = 101;
    for (int& t: nums) {
        int g = t / k;
        if (g * k == t) {
            if (a.empty()) {
                if (g > 1) return k;
                a.push_back(g);
            } else {
                if (g - 1 > a.back()) return (a.back() + 1) * k;
                a.push_back(g);
            }
        }
    }
    if (a.empty()) return k;
    return (a.back() + 1) * k;
}

int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    cout << missingMultiple(a, k) * k;
    return 0;
}