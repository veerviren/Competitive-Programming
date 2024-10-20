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
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    cin >> v;

    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
    dp[0][0] = 0;
    vector<int> v1, v2;

    int tot = 0;

    for(int i = 0; i < n; i++)
    {
        if(v[i] > 0)
        {
            v1.pb(v[i]);
        }
        else if(v[i] < 0)
        {
            v2.pb(-v[i]);
        }
        else{
            tot++;
            sort(all(v1));
            sort(all(v2));

            for(int j = 0; j <= tot; j++)
            {
                if(j != 0)
                {
                    int c1 = j - 1, c2 = tot - j;
                    int val = (upper_bound(all(v1), c1) - v1.begin()) +
                            (upper_bound(all(v2), c2) - v2.begin());
                    dp[tot][j] = max(dp[tot][j], dp[tot - 1][j - 1] + val);
                }
                if(j < tot)
                {
                    int c1 = j, c2 = tot - j - 1;
                    int val = (upper_bound(all(v1), c1) - v1.begin()) +
                            (upper_bound(all(v2), c2) - v2.begin());
                    dp[tot][j] = max(dp[tot][j], dp[tot - 1][j] + val);
                }
            }
            v1.clear();
            v2.clear();
        }
    }

    sort(all(v1));
    sort(all(v2));

    int ans = 0;
    for(int j = 0; j <= m; j++)
    {
        int c1 = j, c2 = m - j;
        int val = (upper_bound(all(v1), c1) - v1.begin()) +
                (upper_bound(all(v2), c2) - v2.begin());
        ans = max(ans, dp[m][j] + val);
    }
    cout << ans << endl;
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