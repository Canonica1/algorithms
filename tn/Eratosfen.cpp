vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
	maximum = max(maximum, 1ll);
	smallest_factor.assign(maximum + 1, 0);
	prime.assign(maximum + 1, true);
	prime[0] = prime[1] = false;
	primes = {};

	for (int p = 2; p <= maximum; p++)
		if (prime[p]) {
			smallest_factor[p] = p;
			primes.push_back(p);

			for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
				if (prime[i]) {
					prime[i] = false;
					smallest_factor[i] = p;
				}
		}
}
