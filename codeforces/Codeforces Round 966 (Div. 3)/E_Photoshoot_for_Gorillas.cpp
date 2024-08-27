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

void Jay_Shree_Krishna() {
    int n, m, k;
    cin >> n >> m >> k;

    int sz;
    cin >> sz;

    vector<int> a(sz);
    cin >> a;
    sort(allr(a));
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // v[i][j] += 1;
            // v[i][j + k + 1] -= 1;

            // v[i + k + 1][j] -= 1;

            // for(int l = i; l < i + k; l++)
            // {
            //     for(int z = j; z < j + k; z++)
            //     {
            //         v[l][z]++;
            //     }
            // }

             int x = min(i + k - 1, n - 1) - max(i, k - 1) + 1;
             int y = min(j + k - 1, m - 1) - max(j, k - 1) + 1;
             v[i][j] = x * y;
        }
    }

    // for (int i = 0; i <= n - k; i++) {
    //     for (int j = 0; j <= m - k; j++) {
    //         v[i][j] += 1;
    //         if (j + k < m + 1) v[i][j + k] -= 1;
    //         if (i + k < n + 1) v[i + k][j] -= 1;
    //         if (i + k < n + 1 && j + k < m + 1) v[i + k][j + k] += 1;
    //     }
    // }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         if (i > 0) v[i][j] += v[i - 1][j];
    //         if (j > 0) v[i][j] += v[i][j - 1];
    //         if (i > 0 && j > 0) v[i][j] -= v[i - 1][j - 1];
    //     }
    // }

    // for(int i = 0; i < n; i ++)
    // {
    //     for(int j = 1; j < m; j++)
    //     {
    //         v[i][j] += v[i][j - 1];
    //     }
    // }

    // for(int j = 0; j < m; j++)
    // {
    //     for(int i = 1; i < n; i++)
    //     {
    //         v[i][j] += v[i - 1][j];
    //     }
    // }

    map<int, int> mp;
    for(auto &x:v)
    {
        for(auto &y:x)
        {
            mp[y]++;
        }
        // cout << x << endl;
    }

    vector<pair<int, int>> p;

    for(auto &x:mp)
    {
        p.push_back({x.fi, x.se});
    }

    sort(allr(p));

    // for(auto &x:p)
    // {
    //     cout << x << endl;
    // }
    // cout << endl;

    int ans = 0;

    int st = 0;
    // cout << "sz " << sz(p) << endl;
    for(int i = 0; i < sz && st < sz(p); i++)
    {
        // cout << "st " << st << endl;
        // cout << "tm " << p[st] << endl;
        // cout << "a[i] " << a[i] << endl;
        if(p[st].second > 0)
        {
            ans += p[st].fi * a[i];
            p[st].second--;
            if(p[st].second == 0)
            {
                st++;
            }
        }
        // cout << "ans " << ans << endl;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
	cin >> t;
    while (t--) Jay_Shree_Krishna();
    return 0;
}