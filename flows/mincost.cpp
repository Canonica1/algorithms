struct MCMF {
    struct E {
        int v, u, w, c, f, idx;
        E(int _v, int _u, int _w, int _c, int _f, int _idx) : v(_v), u(_u), w(_w), c(_c), f(_f), idx(_idx) {}
    };
    int n;
    vector<int> p;
    vector<vector<int>> G;
    vector<int> dist;
    vector<E> e;
    vector<int> from;
    MCMF(int _n) {
        n = _n;
        p.assign(n + 1, {});
        G.assign(n + 1, {});
        dist.assign(n + 1, {});
        from.assign(n + 1, {});
    };
    void add(int v, int u, int w, int c) {
        G[v].push_back(e.size());
        e.push_back(E(v, u, w, c, 0, -1));
        G[u].push_back(e.size());
        e.push_back(E(u, v, -w, 0, 0, -1));
    }
    bool deikstra(int V, int T) {
        set<pair<int, int>> S;
        S.insert({0, V});
        for (int i = 0; i < n; i++) {
            dist[i] = INF;
        }
        dist[V] = 0;
        while (!S.empty()) {
            int v = S.begin()->second;
            S.erase(S.begin());
            for (auto u : G[v]) {
                if (e[u].f == e[u].c)
                    continue;
                int cost = e[u].w + p[e[u].v] - p[e[u].u];
                if (dist[e[u].u] > dist[e[u].v] + cost) {
                    S.erase({dist[e[u].u], e[u].u});
                    dist[e[u].u] = dist[e[u].v] + cost;
                    from[e[u].u] = u;
                    S.insert({dist[e[u].u], e[u].u});
                }
            }
        }
        return dist[T] < INF;
    }
    void fordBellman() {
        for (int i = 0; i < n; i++) {
            dist[i] = 0;
        }
        for (int ii = 0; ii < n; ii++) {
            for (int i = 0; i < e.size(); i++) {
                if (e[i].f == e[i].c)
                    continue;
                if (dist[e[i].u] > dist[e[i].v] + e[i].w) {
                    dist[e[i].u] = dist[e[i].v] + e[i].w;
                }
            }
        }
    }
    pair<int, int> get(int S, int T) {
        // fordBellman();
        int flow = 0;
        int cost = 0;
        while (deikstra(S, T)) {
            for (int i = 0; i < n; i++) {
                p[i] += dist[i];
            }
            int mini = 1e18;
            for (int i = T; i != S; i = e[from[i]].v) {
                mini = min(mini, e[from[i]].c - e[from[i]].f);
            }
            for (int i = T; i != S; i = e[from[i]].v) {
                e[from[i]].f += mini;
                e[from[i] ^ 1].f -= mini;
            }
            cost += p[T] * mini;
            flow += mini;
        }
        return {flow, cost};
    }
};
