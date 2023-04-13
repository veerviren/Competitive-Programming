/*-------------------------------------------------------
      Competitive programming
      Name: Viren Variya (veer_viren)
Nothing is impossible, as you believe you can do it
       You can do it!!!
-------------------------------------------------------*/
 
 
#include <bits/stdc++.h>
 
using namespace std;
 
// #define int long long
#define MOD 1000000007
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD1 998244353
#define INF 1e18
#define ppb pop_back
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define all(X) (X).begin(), (X).end()
#define allr(X) (X).rbegin(), (X).rend()
#define sz(X) (int)X.size()
#define setbits(X) __builtin_popcountll(X)
#define fix(X) fixed << setprecision(X)
#define mem0(X) memset((X), 0, sizeof((X)))
#define mem1(X) memset((X), -1, sizeof((X)))
#define input(a, n) for(int i=0;i<n;i++){cin>>a[i];}
#define print(a) for(auto &i : a){cout<<i<<" ";}
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
// Operator overloads <<, >>
template<typename T1, typename T2> // cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector
istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) { cin >> it; } return istream; }
template<typename T1, typename T2> // cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) { cout << it << " "; } return ostream; }
 
//***********************USEFULL**FUNCTIONS**********************//
int power(int x, int y) {
    int ans = 1;
    x = x % MOD;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)ans = (1ll * ans * x) % MOD;
        y = y >> 1;
        x = (1ll * x * x) % MOD;
    }
    return ans;
}
 
vector<int> SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    vector<int> ANS;
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)if (prime[p])ANS.push_back(p);
    return ANS;
}
 
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
 
int sum(int a) {
    return a * (a + 1) / 2;
}
 
int nCrModpDP(int n, int r) {
    int C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % MOD;
    }
    return C[r];
}
 
int nCr(int n, int r) {
    if (r == 0)
        return 1;
    int ni = n % MOD, ri = r % MOD;
    return (nCr(n / MOD, r / MOD) * nCrModpDP(ni, ri)) % MOD;
}
 
int modInverse(int n) {
    return power(n, MOD - 2);
}
 
int Divisors(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                cnt++;
            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}
 
 
void solve() {
    int n;
    cin>>n;
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
}
 
 
int32_t main() {
    fastio();
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
 
    int t = 1;
//        cin >> t;
    while (t--) solve();
    return 0;
}