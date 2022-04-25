const int  N = 1e5 + 10;
vector<vector<pair<int, int>>> g(N);
vector<bool> used(N);
vector<int> first(N);
vector<int>ans;
void euler(int u) {
	while (first[u] < g[u].size())
	{
		auto p = g[u][first[u]];
		int i = p.first;
		int v = p.second;
		first[u]++;
		if (!used[i])
		{
			used[i] = true;
			euler(v);
			cout << v << " ";
		}
	}

}
int main(){
	int n, m;
	cin >> n >> m;
	int u = -1;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		if (u == -1) u = x;

		g[x].push_back({ i,y });
		g[y].push_back({ i,x });
	}
  euler(1);
}

