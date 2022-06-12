int f[maxn];
f[0] = 1;
for (int i = 1; i < maxn; i++)
    f[i] = i*f[i-1] % mod;

int r[maxn];
r[maxn-1] = inv(f[maxn-1]) // это binpow mod-2;
for (int i = maxn-1; i >= 1; i--)
    r[i-1] = r[i]*i % mod;
