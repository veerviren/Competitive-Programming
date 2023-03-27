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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void dfs(int r, int c, vector<vector<int>> vis, bool &ok, int &k)
{
    int n = vis.size();
    int m = vis[0].size();
    // cout << r << " " << c << " "<< k << endl;
    // cout << "vis " << vis[r][c] << endl;
    if(vis[r][c] == 3)
    {
        // cout << "t " << vis[r][c] << endl;
        ok = true;
        return;
    }

    vis[r][c] = 1;

    int dir[] = {-1, 0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dir[i];
        int nc = c + dir[i + 1];

        if(nr < n && nr >=0 && nc < m && nc >=0 && vis[nr][nc] != 1)
        {
            // cout << "go" <<nr << " " << nc << endl;
            
            if(vis[nr][nc] == 2 && k > 0)
            {
                // cout << "hii" << endl;
                if(k - 2 < 0)
                {
                    return;
                }
                k-= 2;
                // cout << "vis in " << vis[r][c] << endl;
                dfs(nr, nc, vis, ok, k);
            }
            else{
                dfs(nr, nc, vis, ok, k);
            }
            vis[nr][nc] = 1;
        }
    }
    return;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int sr = 0, sc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '@')
            {
                sr = i;
                sc = j;
                vis[i][j] = 1;
            }
            if (c == '#')
            {
                vis[i][j] = 1;
            }
            if (c == 's')
            {
                vis[i][j] = 2;
            }
            if(c == 'x')
            {
                vis[i][j] = 3;
            }
        }
    }

    bool ok = false;
    dfs(sr, sc, vis, ok, k);
    // cout << ok << endl;
    if (!ok)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << "SUCCESS" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // 	cin >> t;
    while (t--)
        solve();
    return 0;
}