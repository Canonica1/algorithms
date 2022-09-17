vector<bool> prime;
vector<int> primes;
void sieve(int maximum) {
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= maximum; ++i) {
        if (prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= maximum; j += i) {
                if (prime[j]) prime[j] = false;
            }
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
