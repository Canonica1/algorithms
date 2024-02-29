struct dinic {
    struct E {
        ll v, u, c, f;
        E(ll _v, ll _u, ll _c, ll _f) {
            v = _v;
            u = _u;
            c = _c;
            f = _f;
        }
    };
    vector<vector<ll>> G;
    vector<E> e;
    ll n;
    vector<ll> pt;
    ll low;
    vector<ll> dist;
    dinic(ll _n) {
        n = _n;
        G.assign(n + 1, {});
        pt.assign(n + 1, {});
        dist.assign(n + 1, {});
    }
    void add(ll u, ll v, ll c) {
        G[u].push_back(e.size());
        e.push_back(E(u, v, c, 0));
        G[v].push_back(e.size());
        e.push_back(E(v, u, 0, 0));
    }
    void rr() {
        for (int i = 0; i < n; i++) {
            shuffle(G[i].begin(), G[i].end(), rnd);
        }
    }
    bool bfs(ll S, ll T) {
        dist.assign(n + 1, INF);
        queue<ll> q;
        q.push(S);
        dist[S] = 0;
        while (!q.empty()) {
            ll v = q.front();
            q.pop();
            for (auto u : G[v]) {
                ll w = e[u].c - e[u].f;
                if (w && dist[e[u].u] == INF && e[u].c - e[u].f >= low) {
                    dist[e[u].u] = dist[v] + 1;
                    q.push(e[u].u);
                }
            }
        }
        return dist[T] != INF;
    }
    ll dfs(ll v, ll T, ll w) {
        if (v == T)
            return w;
        while (pt[v] < G[v].size()) {
            ll u = G[v][pt[v]];
            if (dist[e[u].u] == dist[v] + 1 && e[u].c - e[u].f >= low) {
                ll delta = dfs(e[u].u, T, min(w, e[u].c - e[u].f));
                if (delta) {
                    e[u].f += delta;
                    e[u ^ 1].f -= delta;
                    return delta;
                }
            }
            pt[v]++;
        }
        return 0;
    }
    ll get_flow(ll S, ll T) {
        ll ans = 0;
        for (low = INF; low > 0; low >>= 1) {
            while (bfs(S, T)) {
                pt.assign(n + 1, {});
                while (ll y = dfs(S, T, INF)) {
                    ans += y;
                }
            }
        }
        return ans;
    }
};
