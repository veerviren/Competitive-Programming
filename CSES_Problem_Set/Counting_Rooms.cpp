/*-------------------------------------------------------
Competitive programming
Name: Viren Variya (direction_)
Nothing is impossible, as you believe you can do it
You can do it!!!
-------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
void dfs(int r, int c, vector<vector<int>> &v, int n, int m)
{
    v[r][c] = 1;
 
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
 
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >=0 && nr < n && nc >=0 && nc < m && !v[nr][nc])
        {
            // cout << "go " << nr << " " << nc << endl;
            dfs(nr, nc, v, n, m);
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> v(n, vector<int>(m, 0));
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
        {
            char c;
            cin >> c;
            if(c == '#')
            {
                v[i][j] = 1;
            }
        }
    }
    // for(auto &x:v)
    // {
    //     for(auto &y:x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!v[i][j])
            {
                // cout << "cango " << i << " " << j << endl;
                ans++;
                dfs(i, j, v, n, m);
            }
        }
    }
    cout << ans << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
// 	cin >> t;
    while (t--) solve();
    return 0;
}