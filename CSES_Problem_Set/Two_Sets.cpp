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
    int sum=n*(n+1)/2;
    if(sum%2==1)
    {
        cout<<"NO"<<endl;
    }
    else{
        int ans=sum/2;
        vector<int> v1;
        vector<int> v2;
        for (int i =n; i>=1 ; --i) {
            if(i<=ans)
            {
                v1.pb(i);
                ans-=i;
            }
            else
            {
                v2.pb(i);
            }
        }
        cout<<"YES"<<endl;
        cout<<sz(v1)<<endl;
        for(auto x:v1) cout<<x<<" ";
        cout<<endl;
        cout<<sz(v2)<<endl;
        for(auto x:v2) cout<<x<<" ";
        cout<<endl;
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