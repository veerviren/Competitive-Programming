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
#define input(a, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
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

int getMin(int x,int y)
{
    if(x < y){
        return x;
    }
    else{
        return y;
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void answer(int x, int y)
{
    cout << abs(x - y) << endl;
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int calculate(int x, int y, int n)
{
    x = getMin(x, n - x - 1);
    y = getMin(y, n - y - 1);
    return getMin(x, y);
}

void solve()
{
    int n = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    int score1 = calculate(x1--, y1--, n);
    int score2 = calculate(x2--, y2--, n);
    answer(score1, score2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}