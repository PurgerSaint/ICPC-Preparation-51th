int missingMultiple(vector<int>& nums, int k) {
    vector<int> a;
    for (int& t: a) {
        if (t % k == 0)
            a.push_back(t / k);
    }
    if (a.empty()) return 1;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a[0] > 1) return 1;
    int sz = a.size(), l = 0, r = sz - 1;
    if (a[sz - 1] - a[0] + 1 == sz) return a[sz - 1] + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (r - l == 1 && a[r] - a[l] > 1) return a[l] + 1;
        else if (a[r] - a[mid] > r - mid) l = mid;
        else r = mid;
    }
    return 0;
}