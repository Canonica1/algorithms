#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <fstream>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <numeric> 
#include <cmath> 
#include <bitset> 
#include <stack> 
#include <cassert> 
#include <chrono> 
#include <unordered_map> 
#include <array> 
//if (1.0 * clock() / CLOCKS_PER_SEC > 0.9)
using namespace std;
#define ifthen(x,y,z) (x ? y : z)
#define all(a) (a).begin(), (a).end()
#define sz(a) ((long long)(a).size());
#define ve vector
#define vf(a,n)for (int i = 0; i < (n); i++)cin >> (a)[i];
#define int long long
#define ld long double
#define ya cout << "Yes" << endl
#define no cout << "No" << endl
typedef ve<int> vi;
const int N = 1e7;
int MOD = 1e9 + 7;
const int inf = 1e9;
int mod_mul(int a, int b) { a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD; }
int mod_add(int a, int b) { a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD; }



ve<int> gv(int n) {
	ve<int> a(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 8 + 1;
	}
	return a;
}
int gn() {
	int n = rand() %6+ 1;
	return n;
}

int stupid(int n, ve<int> a) {

}
int smart(int n, ve<int> a) {

}



signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt = 10000;
	/*cin >> tt;*/
	cout.flush();
	while (tt--)
	{
		int n = gn();
		ve<int> a = gv(n);
		int stupidans = stupid(n, a);
		int smartans = smart(n, a);
		if (stupidans != smartans)
		{
			cout << n << endl;
			for (auto x : a)
			{
				cout << x << " ";
			}
			cout << "stupid = " << stupidans << endl;
			cout << "smart = " << smartans << endl;
		}

	}
}

//1 1 1 1 2 2
// ( ) ( ) (( )) 
// 
// 
