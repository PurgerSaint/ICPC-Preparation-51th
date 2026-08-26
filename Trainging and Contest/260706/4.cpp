#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    int sum = 0, min_sum = INT_MAX, ans = 0, start = 0;
    for (int i = 0; i < k; i++)
        sum += a[i];
    min_sum = min(min_sum, sum);
    // cout << "i:" << start << " sum:" << sum << "\n";
    for (int j = k; j < n; j++) {
        sum += a[j] - a[start];
        start++;
        // cout << "i:" << start << " sum:" << sum << "\n";
        if (sum < min_sum) {
            // cout << "min" << "\n";
            ans = start;
            min_sum = sum;
        }
    }
    cout << (ans + 1);
    return 0;
}