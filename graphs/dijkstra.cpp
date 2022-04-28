	set<pair<int, int>> s;
	ve<int>a(n);

	forn (i,n)
	{
		if (i == x1)
		{
			s.insert({ 0,i });
			a[i] = 0;
			continue;
		}
		a[i] = 1e9;
		s.insert({ 1e9, i });
	}

	while (!s.empty())
	{

		pair<int, int> mini = *s.begin();
		int minV = mini.second;
		s.erase(mini);
		for (auto x : g[minV])
		{
			if (x.second == minV || s.find({ a[x.second] , x.second }) == s.end())
			{
				continue;
			}
			s.erase({ a[x.second] , x.second });
			a[x.second] = min(a[x.second], a[minV] + x.first);
			s.insert({  a[x.second],x.second });
		}
	}
