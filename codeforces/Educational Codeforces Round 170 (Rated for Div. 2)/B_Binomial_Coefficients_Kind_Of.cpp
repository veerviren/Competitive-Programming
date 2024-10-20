/*-------------------------------------------------------
Competitive programming
Name: Viren Variya (direction_)
Nothing is impossible, as you believe you can do it
You can do it!!!
-------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define allr(X) (X).rbegin(), (X).rend()
#define sz(X) (int)X.size()
#define setbits(X) __builtin_popcountll(X)
#define fix(X) fixed << setprecision(X)
#define mem0(X) memset((X), 0, sizeof((X)))
#define mem1(X) memset((X), -1, sizeof((X)))
#define input(a, n) for(int i=0;i<n;i++){cin>>a[i];}
// Operator overloads <<, >>
template<typename T1, typename T2>
// cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T>
// cin >> vector
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v) { cin >> it; }
    return istream;
}

template<typename T1, typename T2>
// cout << pair 
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << ' ' << p.second); }

template<typename T>
// cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c) { cout << it << ' '; };
    return ostream;
}
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
#define MOD 1000000007



int find(int x, int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = find(x, y / 2) % MOD;
    if (y % 2 == 0)
        return (temp * temp) % MOD;
    else
        return (x % MOD) * (temp % MOD) * (temp % MOD);
}

void Jay_Shree_Krishna() {
    int t;
    cin >> t;

    vector<int> n(t), k(t);
    cin >> n >> k;

    for(int i = 0; i < t; i++)
    {
        if(k[i] == 0 ||  n[i] == k[i])
        {
            cout << 1 << endl;
        }
        else{
            int p = find(2, k[i] - 1);
            cout << (2 * p) % MOD  << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
// 	cin >> t;
    while (t--) Jay_Shree_Krishna();
    return 0;
}