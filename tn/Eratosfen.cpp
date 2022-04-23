    vector<bool> a(n + 1, true);
    for (ll i = 2; i<= n; i++)
    {
        if (a[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                a[j] = false;
            }
        }
    }
