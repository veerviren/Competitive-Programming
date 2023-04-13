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
    cin >> n;
    vector<int> v;
    if(n==1)
    {
        cout<<"1";
    } else if(n==2 || n==3){
        cout<<"NO SOLUTION";
    }else {
        while (n > 0) {
            if (n % 2 != 0) {
                cout << n << " ";
                n--;
            } else {
                v.pb(n);
                n--;
            }
        }
        for (int i = 0; i < sz(v); ++i) {
            cout << v[i] << " ";
        }
    }
 
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