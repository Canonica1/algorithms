int gcd(int a, int b) {
    wihle (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
