vector<bool> isprime(N, 1);
vector<int> primes;
void sieve() {
    for (int i = 2; i <= N; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            isprime[i * p] = 0;
        }
    }
}
int factorize(int x) {
    int factors = 0;
    for (auto i : primes) {
        if (i * i> x) break;
        while (x % i == 0) {
            factors++;
            x /= i;
        }
    }
    if (x != 1) {
        factors++;
    }
    return factors;
}
