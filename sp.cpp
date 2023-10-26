#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ld long double
#define int long long
#define uint unsigned long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl '\n'
const int N = 2e5;
const int INF = 1e18;
const int mod = 1e9 + 7;
const ld EPS = 1e-6;
random_device rn;
mt19937 rnd(rn());
typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
int binpow(int n,int m) {
    if (m == 0) return 1;
    if (m % 2) {
        return binpow(n, m - 1) * n % mod;
    } else {
        int b = binpow(n, m / 2) % mod;
        return b * b % mod;
    }
}
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
//dots
void dfs(int v, int p) {
    used[v] = true;
    tin[v] = timer++;
    tup[v] = tin[v];
    int ch = 0;
    bool ok = false;
    for (auto to : g[v])
    {
        if (to == p)
        {
            continue;
        }
        if (used[to])
        {
            tup[v] = min(tup[v], tin[to]);
        }
        else {
            dfs(to, v);
            tup[v] = min(tup[v], tup[to]);
            ch++;
            if (tup[to] >= tin[v] && p != -1)
            {
                ok = true;
            }
        }
    }
    if (p == 1 && ch > 1)
    {
        ok = true;
    }
    if (ok)
    {
        cout << "CUT = " << v + 1<< endl;
    }
}
//dots
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
struct SegmentTreeMass
{
    struct Node
    {
        int sum = 0;
        int add = 0;

        Node(int Sum = 0, int Add = 0)
        {
            sum = Sum;
            add = Add;
        }
    };

    Node neutral = Node();
    int n;
    vector<Node> tree;

    SegmentTreeMass(vector<int>& start)
    {
        n = start.size();
        tree.resize(4 * n + 228);
        init(start);
    }

    SegmentTreeMass(int N)
    {
        n = N;
        tree.resize(4 * n + 228);
        vector<int> start(n, 0);
        init(start);
    }

    Node merge(Node n1, Node n2)
    {
        return Node(n1.sum + n2.sum);
    }

    void fix(int v, int l, int r)
    {
        tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
    }

    void apply(int v, int l, int r, int val)
    {
        tree[v].add += val;
        tree[v].sum += val * (r - l);
    }

    void init(int v, int l, int r, vector<int>& start)
    {
        if (l + 1 == r)
        {
            tree[v] = Node(start[l], 0);
            return;
        }

        int m = (r + l) / 2;
        init(v * 2 + 1, l, m, start);
        init(v * 2 + 2, m, r, start);
        fix(v, l, r);
    }

    void init(vector<int>& start)
    {
        init(0, 0, n, start);
    }

    void push(int v, int l, int r)
    {
        int m = (r + l) / 2;

        apply(v * 2 + 1, l, m, tree[v].add);
        apply(v * 2 + 2, m, r, tree[v].add);
        tree[v].add = 0;
    }

    // [l: r)
    Node query(int v, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return tree[v];
        }
        if (r <= ql || qr <= l)
        {
            return neutral;
        }

        int m = (r + l) / 2;
        push(v, l, r);
        return merge(
                query(v * 2 + 1, l, m, ql, qr),
                query(v * 2 + 2, m, r, ql, qr));

    }

    Node query(int ql, int qr)
    {
        return query(0, 0, n, ql, qr);
    }

    void add(int v, int l, int r, int ql, int qr, int val)
    {
        if (ql <= l && r <= qr)
        {
            apply(v, l, r, val);
            return;
        }
        if (r <= ql || qr <= l)
        {
            return;
        }

        int m = (r + l) / 2;
        push(v, l, r);
        add(v * 2 + 1, l, m, ql, qr, val);
        add(v * 2 + 2, m, r, ql, qr, val);
        fix(v, l, r);
    }

    void add(int ql, int qr, int val)
    {
        add(0, 0, n, ql, qr, val);
    }

};
int gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
//rmq
int const MAX_N = 1000000;
const int MAX_LOG = 25;
int log_a[MAX_N];
struct rmq{
    vector<vector<int>> ST;
    void buildLg() {
        log_a[1] = 0;
        for (int i = 2; i < MAX_N; i++)
        {
            log_a[i] = log_a[i / 2] + 1;
        }
    }
    void bulid(vector<int> &a) {
        int n = a.size();
        ST.assign(n + 1, vector<int> (MAX_LOG));
        for (int i = 0; i < n; i++)
        {
            ST[i][0] = a[i];
        }
        for (int k = 1; k < MAX_LOG; k++)
        {
            for (int i = 0; i + (1 << (k - 1)) -1 < n; i++)
            {
                ST[i][k] = max(ST[i][k - 1], ST[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int get_max(int l, int r) {
        int length = r - l ;
        int k = log_a[length];
        return max(ST[l][k], ST[r - (1 << k) + 1][k]);
    }
};
//rmq
vector<int> pref_func(string s) {
    vector<int> P(s.size(),0);
    int n = s.size();
    int j;
    for (int i = 1; i < n; i++)
    {
        j = P[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = P[j - 1];
        }
        if (s[i] == s[j])
        {
            P[i] = j + 1;
        }
        else {
            P[i] = 0;
        }
    }
    return P;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

}

//from os import popen, system
//from random import randint
//import random
//import string
//system('g++ main.cpp -std=c++17 -o main')
//system('g++ 4.cpp -std=c++17 -o 4')
//def generate_random_string(length):
//    letters = string.ascii_lowercase
//    rand_string = ''.join(random.choice(letters) for i in range(length))
//    return rand_string
//def gen():
//    with open('test.txt', 'w') as f:
//        n = randint(1, 100)
//        f.write(str(n) + " " + str(randint(1, n)) + '\n')
//        for i in range(n):
//            y = randint(1, 100)
//            f.write(str(y) + " ")
//
//
//for test in range(1, 10000000000):
//    gen()
//    # smart = str(popen('4 < test.txt').readline())
//    smart = str(popen('main < test.txt').readline())
//    correct = str(popen('4 < test.txt').readline())
//    if smart == correct:
//        print("OK")
//    else:
//        print("NO")
//        print("test = ", open('test.txt').read(), end="\n")
//        print("correct = ", correct)
//        print("smart = ", smart)
//        break
all:
	g++ sol.cpp -std=c++20 -Wall -Wextra  -Wshadow -o sol -DONPC -fsanitize=address -fsanitize=undefined  -g
	./sol < ./test.txt
al:

% : %.cpp al
	$(CXX) $@.cpp -std=c++20 -Wall -Wextra  -Wshadow $(CXXFLAGS) -o $@ -DONPC -fsanitize=address -fsanitize=undefined -g
	./$@ < ./test.txt

st: stupid.cpp test.txt
	g++ stupid.cpp -std=c++20 -Wall -Wextra  -Wshadow -o stupid -DONPC -fsanitize=address -fsanitize=undefined -g
	./stupid < ./test.txt
time: gen.cpp test.txt sol.cpp
	g++ gen.cpp -std=c++20 -Wall -Wextra  -Wshadow -o gen -DONPC -fsanitize=address -fsanitize=undefined -g
	./gen > ./test.txt
	g++ sol.cpp -std=c++20 -o sol -O3
	time -f %e ./sol < ./test.txt > /dev/null
grader: sol.cpp grader.cpp
	g++ sol.cpp grader.cpp -o sol
	./sol
