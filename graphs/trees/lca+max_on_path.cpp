bool a(int u, int v) {
	return tin[u] <= tin[v] && tin[v] < tout[u];
}

void dfs(int v, int p, ve<ve<int>>& up, ve<ve<int>>& mx) {

	tin[v] = t++;
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i] == p) continue;
		dfs(G[v][i], v, up, mx);
		mx[G[v][i]][0] = max(mx[G[v][i]][0], cost[v][i]);
		up[G[v][i]][0] = v;
	}
	tout[v] = t;
}
int lca(int v, int u, ve<ve<int>>& up) {
	if (a(v, u)) return v;
	if (a(u, v)) return u;
	for (int l = logn - 1; l >= 0; l--)
		if (!a(up[v][l], u))
			v = up[v][l];
	return up[v][0];
}
int get_max(int v, int u, ve<ve<int>>& up, ve<ve<int>>& mx) {
	int res = -inf;
	if (a(v, u)) {
		for (int l = logn - 1; l >= 0; l--)
			if (!a(up[u][l], v))
				res = max(res, mx[u][l]),
				u = up[u][l];
		return max({ res, mx[u][0] });
	}
	if (a(u, v)) {
		for (int l = logn - 1; l >= 0; l--)
			if (!a(up[v][l], u))
				res = max(res, mx[v][l]),
				v = up[v][l];
		return max({ res, mx[v][0] });

	}
	for (int l = logn - 1; l >= 0; l--)
		if (!a(up[v][l], u))
			res = max(res, mx[v][l]),
			v = up[v][l];
	for (int l = logn - 1; l >= 0; l--)
		if (!a(up[u][l], v))
			res = max(res, mx[u][l]), u = up[u][l];
	return max({ res, mx[v][0], mx[u][0] });
}
signed main(){
		dfs(1, 1, up, mx);
		for (int l = 1; l < logn; l++) {
			for (int v = 1; v <= n; v++)
			{
				up[v][l] = up[up[v][l - 1]][l - 1];
 			}
		}
}
  
