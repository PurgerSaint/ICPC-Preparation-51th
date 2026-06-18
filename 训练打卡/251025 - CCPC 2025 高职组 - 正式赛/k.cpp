#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
int three(int a) {
    return a * a * a;
}
int main() {
    IOS;
    vector<int> t;
    for (int i = 1; i <= 1000; i++) {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100;
        if (three(a) + three(b) + three(c) == i)
            t.push_back(i);
    }
    for (int i = 0; i < t.size(); i++)
        cout << t[i] << (i != t.size() - 1 ? " " : "");
    return 0;
}