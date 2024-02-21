/*-------------------------------------------------------
Competitive programming
Name: Viren Variya (direction_)
Nothing is impossible, as you believe you can do it
You can do it!!!
-------------------------------------------------------*/
#include <bits/stdc++.h>
#include <iostream>
#include <set>
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

void getAllSubsequence(vector<char> set, string previous,
                                    int n, int k,vector<string> &v)
{
    if (k == 0)
    {
        v.pb(previous);
        return;
    }
 
    for (int i = 0; i < n; i++)
    {
        string curr;
        curr = previous + set[i];
        getAllSubsequence(set, curr, n, k - 1, v);
    }
}

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    string s;
    cin >> s;

    string ans = "";

    int block = 0;

    set<int> st;
    for(auto &x:s)
    {
        st.insert(x);
        if(st.size() == k)
        {
            block++;
            st.clear();
            ans += x;
        }
    }
    char last = 'a';
    for(char i = 'a'; i <= 'a' + k; i++)
    {
        if(st.find(i) == st.end())
        {
            ans += i;
            last = i;
            break;
        }
    }

    for(int i = ans.size(); i < n; i++)
    {
        ans += last;
    }

    if(block >= n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
	cin >> t;
    while (t--) solve();
    return 0;
}