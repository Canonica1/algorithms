int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1,y1;
    int g = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}
int crt(int d1, int m1, int d2, int m2) {
    int a = m1;
    int b = -m2;
    int c = d2 - d1;
    int x, y;
    int g = gcd(a,b,x,y);
    if (c % g != 0){
        return -INF;
    }
    x *=c / g;
    y *= c/ g;
    x = (x % m2 + m2) % m2;
    x=  x * m1 + d1;
    return x %lcm(m1,m2);

}
