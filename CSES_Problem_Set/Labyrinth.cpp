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
#define input(a, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
// Operator overloads <<, >>
template <typename T1, typename T2>
// cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
 
template <typename T>
// cin >> vector
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
    {
        cin >> it;
    }
    return istream;
}
 
template <typename T1, typename T2>
// cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << ' ' << p.second);
}
 
template <typename T>
// cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
    {
        cout << it << ' ';
    };
    return ostream;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int sr = 0, sc = 0, er = 0, ec = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                vis[i][j] = 1;
            }
            if (c == 'A')
            {
                sr = i;
                sc = j;
            }
            if (c == 'B')
            {
                er = i;
                ec = j;
            }
        }
    }
 
    // for(auto &x:vis)
    // {
    //     for(auto &y:x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    bool ok = 0;
    vector<vector<char>> direction(n, vector<char>(m));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        // cout << r << " " << c << endl;
        q.pop();
 
        if( r == er && c == ec)
        {
            ok = 1;
            break;;
        }
 
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        char dd[] = {'U', 'L', 'D', 'R'};
 
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            // cout << "go " << nr << " " << nc << endl;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0)
            {
                vis[nr][nc] = 1;
                direction[nr][nc] = dd[i];
                q.push({nr, nc});
            }
 
        }
    }
 
    if(!ok) {
        cout << "NO" << endl;
        return;
    }
 
    int cr = er, cc = ec;
    string ans = "";
    while(!(cr == sr && cc == sc))
    {
        ans += direction[cr][cc];
 
        if(direction[cr][cc] == 'D')
        {
            cr--;
        }
        else if(direction[cr][cc] == 'U')
        {
            cr++;
        }
        else if(direction[cr][cc] == 'R')
        {
            cc--;
        }
        else{
            cc++;
        }
    }
    reverse(all(ans));
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}