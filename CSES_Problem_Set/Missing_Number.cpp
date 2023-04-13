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
    int n,sum=0,a;
    cin>>n;
 
    for (int i = 0; i < n-1; ++i) {
        cin>>a;
        sum+=a;
    }
    cout<<(n*(n+1)/2) - sum;
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