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
    int n;
    cin>>n;
    int mx=0;
    int ans=0;
    for (int i = 0; i < n; ++i) {
        int x;                      //2,5,1,4
        cin>>x;
        mx=max(x,mx);               //3,5,5,5
        ans+=mx-x;                  //1,1,,6,
    }
    cout<<ans;
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