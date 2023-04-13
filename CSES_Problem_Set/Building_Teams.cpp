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
 
 
bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int col)
{
    vis[node] = !col;
 
    for(auto &x:adj[node])
    {
        if(vis[x] == -1)
        {
            if(dfs(x, adj, vis, !col) == false){
                return false;
            }
        }
        else if(vis[x] == vis[node])
        {
            return false;
        }
    }
    return true;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    vector<int> vis(n + 1, -1);
    vector<vector<int>> adj(n + 1);
 
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    for (int i = 1; i <= n; i++)
    {
        if(vis[i] == -1)
        {
            if(dfs(i, adj, vis, 0) == false){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vis[i]++;
        cout << vis[i] << " ";
    }
    cout << endl;
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
