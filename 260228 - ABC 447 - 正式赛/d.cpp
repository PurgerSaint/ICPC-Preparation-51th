#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    string s; cin >> s;
    unordered_map<char, queue<int>> hash;
    int n = s.size();
    for (int i = 0; i < n; i++)
        hash[s[i]].push(i);
    if (!hash.count('A') || !hash.count('B') || !hash.count('C')) {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    while (!hash['A'].empty() && !hash['B'].empty() && !hash['C'].empty()) {
        int a = hash['A'].front();
        hash['A'].pop();

        int b = -1;
        while (!hash['B'].empty() && hash['B'].front() <= a) hash['B'].pop();
        if (hash['B'].empty()) break;
        b = hash['B'].front();
        hash['B'].pop();

        while (!hash['C'].empty() && hash['C'].front() <= b) hash['C'].pop();
        if (hash['C'].empty()) break;
        hash['C'].pop();

        cnt++;
    }
    cout << cnt;
    return 0;
}