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
			if (tup[to] > tin[v])
			{
				cout << "BRINGE " << v + 1 << " " << to + 1 << endl;
			}
		}
	}
}
