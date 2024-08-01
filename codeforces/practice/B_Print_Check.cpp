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
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> r1(5001), c1(50001);
    for(int i = 0; i < k; i++)
    {
        int type;
        cin >>type;

        if(type == 1)
        {
            int r, a;
            cin >> r >> a;
            r--;
            r1[r].first = a;
            r1[r].second = i;
        }
        else{
            int c, a;
            cin >> c >> a;
            c--;
            c1[c].first = a;
            c1[c].second = i;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(r1[i].first && c1[j].first)
            {
                if(r1[i].second > c1[j].second)
                {
                    cout << r1[i].first << " ";
                }
                else{
                    cout << c1[j].first << " ";
                }
            }
            else if(r1[i].first)
            {
                cout << r1[i].first << " ";
            }
            else if(c1[j].first)
            {
                cout << c1[j].first << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
	// cin >> t;
    while (t--) Jay_Shree_Krishna();
    return 0;
}