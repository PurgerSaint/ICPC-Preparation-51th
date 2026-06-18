vector<vector<pair<int,int>>> mp;
struct State {
    int node;   // 当前节点
    ll weight;  // 前往节点的距离[权值]
    State(int n, ll w) : node(n), weight(w) {}
    // 小顶堆[确保升序第一个最小]
    bool operator<(const State& other) const {
        return weight > other.weight;
    } 
};
void Dijkstra(int n, int start) {
    vector<bool> vis(n + 1, false);
    vector<ll> dis(n + 1, LLONG_MAX);   // 从start到每个点的带权距离
    priority_queue<State> pq;           // 小顶堆[确保升序]
    pq.push(State(start, 0));
    dis[start] = 0;
    while (!pq.empty()) {
        State t = pq.top(); pq.pop();
        int u = t.node; ll w = t.weight;
        if (vis[u]) continue;   // 距离已更新过,就跳过
        vis[u] = true;
        for (pair<int,int>& p : mp[u]) {
            int v = p.first, w2 = p.second + w;
            // 标准Dijkstar写法
            if (dis[v] > w2) {
                dis[v] = w2;
                pq.push(State(v, dis[v])); 
            }
        }
    }
}