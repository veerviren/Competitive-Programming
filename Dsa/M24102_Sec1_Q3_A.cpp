#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int mx = 0;
        for(int j = 0; j <= n - i; j++)
        {
            int mi = *min_element(v.begin() + j, v.begin() + j + i);
            mx = max(mx, mi);
        }
        cout << mx << " ";
    }
    cout << endl;

}