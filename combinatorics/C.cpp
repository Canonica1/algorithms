    ve<ve<ll>> C(n + 1);
    for (int i = 0; i <= n ; i++)
    {
        C[i].resize(i + 1); C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
