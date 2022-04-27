const int N = 100 * 1000 + 17;
int n, m;
ve<int> g[N];
ve<int> tin(N);
ve<int> tup(N);
int timer = 0;
bool used[N];

void dfs(int v, int p) {
	used[v] = true;
	tin[v] = timer++;
	tup[v] = tin[v];
	int ch = 0;
	bool ok = false;
	for (auto to : g[v])
	{
		if (to == p)
		{
			continue;
		}
		if (used[to])
		{
			tup[v] = min(tup[v], tin[to]);
		}
		else {
			dfs(to, v);
			tup[v] = min(tup[v], tup[to]);
			ch++;
			if (tup[to] >= tin[v] && p != -1)
			{
				ok = true;
			}
		}
	}
	if (p == 1 && ch > 1)
	{
		ok = true;
	}
	if (ok)
	{
		cout << "CUT = " << v + 1<< endl;
	}
}
int main(){
	cin >> n >> m;
	forn(i, m) {
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	dfs(0, -1);
}
  
