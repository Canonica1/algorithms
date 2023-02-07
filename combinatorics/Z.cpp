
struct Z {
	vector<int> f;
	vector<int> r;
	void initFacts() {
		f.assign(N, 0);
		r.assign(N, 0);
		f[0] = 1;
		for (int i = 1; i < N; i++)
			f[i] = i * f[i - 1] % mod;

		r[N - 1] = binpow(f[N - 1], mod - 2); // это binpow mod-2;
		for (int i = N - 1; i >= 1; i--)
			r[i - 1] = r[i] * i % mod;
	}
	int choose(int n, int k) {
		return f[n] * r[n - k] % mod * r[k] % mod;
	}
	int perm(int n, int k) {
		return f[n] * r[n-k] % mod;
	}
};
