vector<int> manaker(string s) {
    int n = s.size();
    vector<int> d(n, 1);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            d[i] = min(d[(r + l) - i], r - i + 1);
        }
        while (i + d[i] < n &&  i - d[i] >= 0 && s[d[i] + i] == s[i - d[i]])
        {
            d[i] ++;
        }
        if (i + d[i] - 1 > r)
        {
            r = i + d[i] - 1;
            l = i - d[i] + 1;
        }
    }
    return d;
}
