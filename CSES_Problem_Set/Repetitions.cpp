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
 
void solve() {
    string s;
    cin >> s;
    int c = 0;
    int mx = 0;
    char l = 'A';
    for (int i = 0; i < s.size(); ++i) {
        if (l == s[i]) {
            c++;
            mx = max(c, mx);
        } else {
            l = s[i];
            c=1;
        }
    }
    cout << mx;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    //    cin >> t;
    while (t--) solve();
    return 0;
}