/*-------------------------------------------------------
Competitive programming
Name: Viren Variya (direction_)
Nothing is impossible, as you believe you can do it
You can do it!!!
-------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>
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

    vector<int> a(n);
    cin >> a;

    vector<int> pre, suf;
    pre = a;
    suf = a;

    for(int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    for(int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + a[i];
    }

    // cout << pre << endl;
    // cout << suf << endl;
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        int target = suf[i];
        // cout << "target " << target << endl; 
        int st = 0;
        int ed = i - 1;
        // cout << "St " << st << " ed " << ed << endl;
        while(st <= ed)
        {
            int mid = st + (ed - st) / 2;

            if(pre[mid] == target)
            {
                int cur = mid + (n - i + 1);
                ans = max(ans, cur);
                break;
            }
            else if(pre[mid] > target)
            {
                ed = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
    }
    cout << ans << endl;
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