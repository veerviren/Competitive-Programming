#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int INF = 1e9;

struct Edge
{
    int to, w;
    Edge(int to, int w) : to(to), w(w) {}
};

int n, m, u, L, K;
vector<Edge> adj[MAXN];
int dist[MAXN];
bool vis[MAXN];

// Dijkstra's algorithm to find shortest paths from u to all nodes
void dijkstra(int u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n + 1, INF);
    fill(vis, vis + n + 1, false);
    dist[u] = 0;
    pq.push({0, u});
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        if (vis[v])
            continue;
        vis[v] = true;
        for (const auto &e : adj[v])
        {
            int to = e.to, w = e.w;
            if (dist[to] > dist[v] + w)
            {
                dist[to] = dist[v] + w;
                pq.push({dist[to], to});
            }
        }
    }
}

// Recursive function to generate all paths of length L from u
void dfs(int v, int d, vector<int> &path, vector<vector<int>> &paths)
{
    if (d == L)
    {
        paths.push_back(path);
        return;
    }
    for (const auto &e : adj[v])
    {
        int to = e.to, w = e.w;
        path.push_back(w);
        dfs(to, d + 1, path, paths);
        path.pop_back();
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        cin >> n >> m >> u >> L >> K;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dijkstra(u);
        vector<int> path;
        vector<vector<int>> paths;
        dfs(u, 0, path, paths);
        int ans = -1;
        for (const auto &p : paths)
        {
            vector<int> sorted_weights = p;
            sort(sorted_weights.begin(), sorted_weights.end());
            if (sorted_weights.size() < K)
                continue;
            ans = max(ans, sorted_weights[K - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
