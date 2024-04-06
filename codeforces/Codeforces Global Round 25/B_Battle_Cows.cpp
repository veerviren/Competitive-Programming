/*-------------------------------------------------------
Competitive programming
Name: Viren Variya (direction_)
Nothing is impossible, as you believe you can do it
You can do it!!!
-------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <random>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <complex>
#include <math.h>
#include <cstring>
#include <chrono>
#include <string>
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
template <typename T1, typename T2>
// cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T>
// cin >> vector
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
    {
        cin >> it;
    }
    return istream;
}

template <typename T1, typename T2>
// cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << ' ' << p.second);
}

template <typename T>
// cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
    {
        cout << it << ' ';
    };
    return ostream;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void find(vector<int> &a, int n, int k, int &ans, int target)
{
    int mx = a[0];

    for (int i = 1; i < n; i++)
    {
        mx = max(mx, a[i]);
        // cout << "mx " << mx << " target " << target << endl;
        if (mx > target)
        {
            break;
        }

        if (i >= k - 1)
        {
            ans++;
        }
    }
}

void Jay_Shree_Krishna()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    cin >> a;

    int ans1 = 0;
    int target = a[k - 1];

    find(a, n, k, ans1, target);
    // cout << "a " << a << endl;
    // cout << "ans1 " << ans1 << endl;

    int ans2 = 0;
    vector<int> temp = a;
    swap(temp[0], temp[k - 1]);
    find(temp, n, 0, ans2, target);
    // cout << "a " << temp << endl;
    // cout << "ans2 " << ans2 << endl;

    int ans3 = 0;
    temp = a;
    // cout << "temp " << temp << endl;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] > temp[k - 1])
        {
            // cout << "mx " << temp[k - 1] << endl;
            // cout << "i " << temp[i] << endl;
            swap(temp[k - 1], temp[i]);
            find(temp, n, i + 1, ans3, target);
            break;
        }
    }

    // cout << "a " << temp << endl;
    // cout << "ans3 " << ans3 << endl;
    cout << max({ans1, ans2, ans3}) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        Jay_Shree_Krishna();
    return 0;
}