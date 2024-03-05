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

int ask(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    int d;
    cin >> d;
    return d;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int res1 = ask(1, 1);
    int res2 = 0, res3 = 0;
    int x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    if (res1 <= n - 1)
    {
        x2 = res1 + 1;
        y2 = 1;
        res2 = ask(res1 + 1, 1);
    }
    else
    {
        x2 = n;
        y2 = res1 - n + 2;
        res2 = ask(n, res1 - n + 2);
    }

    if (res1 <= m - 1)
    {
        x3 = 1;
        y3 = res1 + 1;
        res3 = ask(1, res1 + 1);
    }
    else
    {
        x3 = res1 - m + 2;
        y3 = m;
        res3 = ask(res1 - m + 2, m);
    }

    x3 += (res3 / 2);
    y3 -= (res3 / 2);
    x2 -= (res2 / 2);
    y2 += (res2 / 2);

    int res4 = ask(x3, y3);

    if (res4 == 0)
    {
        cout << "! " << x3 << " " << y3 << '\n';
        fflush(stdout);
    }
    else
    {
        cout << "! " << x2 << " " << y2 << '\n';
        fflush(stdout);
    }
    
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