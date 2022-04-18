vector<int> pref_func(string s) {
	vector<int> P(s.size(),0);
	int n = s.size();
	int j;
	for (int i = 1; i < n; i++)
	{
		j = P[i - 1];
		while (j > 0 && s[i] != s[j])
		{
			j = P[j - 1];
		}
		if (s[i] == s[j])
		{
			P[i] = j + 1;
		}
		else {
			P[i] = 0;
		}
	}
	return P;
}
