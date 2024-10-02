/*-------------------------------------------------------
Competitive programming
Name: Viren Variya (direction_)
Nothing is impossible, as you believe you can do it
You can do it!!!
-------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

bool query(string t)
{
    cout << "? " << t << endl;
    int res;
    cin >> res;
    return res; 
}

void solve() {
    int n;
    cin >> n;

    string ans;
    if(query("1"))
    {
        ans = "1";
    }
    else{
        ans = "0";
    }

    while(ans.size() < n)
    {
        if(query(ans + '0'))
        {
            ans +=  '0';
        }
        else if(query(ans + '1'))
        {
            ans += '1';
        }
        else{
            break;
        }
    }

    while (ans.size() < n)
    {
        if(query('0' + ans))
        {
            ans = '0' + ans;
        }
        else{
            ans  = '1' + ans;
        }
    }

    cout << "! " << ans << endl;
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