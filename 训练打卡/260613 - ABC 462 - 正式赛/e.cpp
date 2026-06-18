#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
double angleClock(int hour, int minutes) {
    double hour_angle = hour % 12 * 30 + minutes / 60.0 * 30;
    cout << (hour % 12) << " " << (minutes / 60.0) << "\n";
    double minutes_angle = minutes * 6;
    cout << "hour_angle:" << hour_angle << " " << "minutes_angle:" << minutes_angle << "\n";
    double ans = abs(hour_angle - minutes_angle);
    if (ans - 180 > 1e-9)
        ans = min(ans, 360 - max(hour_angle, minutes_angle) + min(hour_angle, minutes_angle));
    return ans;
}

int main() {
    ios;
    int a, b; cin >> a >> b;
    cout << angleClock(a, b);    
    return 0;
}