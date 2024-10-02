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
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void Jay_Shree_Krishna() {
    int n;
    cin >> n;

    vector<int> v(n);
    cin >> v;

    int mx = *max_element(all(v));

    vector<int> copy = v;
    set<pair<int, int>> ans;
    sort(copy.begin(), copy.begin() + mx);
    sort(copy.begin() + mx, copy.end());

    bool ok = 0;
    int st = 1;
    for (int i = 0; i < mx; i++) {
        if(copy[i] != st++) {
            ok = 1;
            break;
        }
    }
    st = 1;
    for(int i = mx; i < n; i++) {
        if(copy[i] != st++) {
            ok = 1;
            break;
        }
    }

    if(!ok)
    {
        // cout << mx << " " << n - mx << endl;
        ans.insert({mx, n - mx});
    }

    ok = 0;

    copy = v;
    sort(copy.begin(), copy.begin() + n - mx);
    sort(copy.begin() + n - mx, copy.end());
    st = 1;
    for (int i = 0; i < n - mx; i++) {
        if(copy[i] != st++) {
            ok = 1;
            break;
        }
    }
    st = 1;
    for(int i = n - mx; i < n; i++) {
        if(copy[i] != st++) {
            ok = 1;
            break;
        }
    }

    if(!ok)
    {
        // cout << n - mx << " " << mx << endl;
        ans.insert({n - mx, mx});
    }

    if(sz(ans))
    {
        cout << sz(ans) << endl;
        for(auto &it : ans)
        {
            cout << it << endl;
        }
    }
    else
    {
        cout << 0 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
	cin >> t;
    while (t--) Jay_Shree_Krishna();
    return 0;
}