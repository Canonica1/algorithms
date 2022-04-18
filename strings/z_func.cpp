vector<int> z_func(string s) {
	vector<int> Z(s.size(),0);
	int n = s.size();
	int l = 0;
	int r = 0;
	for (int i = 1; i < n; i++)
	{
		if (i <= r)
		{
			Z[i] = min(Z[i - l], r - i);
		}
		while (i + Z[i] < n && s[Z[i] + i] == s[Z[i]])
		{
			Z[i] ++;
		}
		if (i + Z[i] > r)
		{
			r = i + Z[i];
			l = i;
		}
	}
	return Z;
}
