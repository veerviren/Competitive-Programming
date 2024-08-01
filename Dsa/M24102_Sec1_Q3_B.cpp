#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void printMaxOfMin(vector<int> v, int n) {
    vector<int> prev(n, -1), next(n, n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && v[s.top()] >= v[i]) {
            s.pop();
        }
        if (!s.empty()) {
            prev[i] = s.top();
        }
        s.push(i);
    }
    cout << "prev ";
    for(auto &x:prev)
    {
        cout << x << " ";
    }
    cout << endl;
    while (!s.empty()) s.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && v[s.top()] >= v[i]) {
            s.pop();
        }
        if (!s.empty()) {
            next[i] = s.top();
        }
        s.push(i);
    }
    cout << "next ";
    for(auto &x:next)
    {
        cout << x << " ";
    }
    cout << endl;

    vector<int> result(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int length = next[i] - prev[i] - 1;
        result[length] = max(result[length], v[i]);
    }

    for (int i = n - 1; i >= 1; --i) {
        result[i] = max(result[i], result[i + 1]);
    }

    for (int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    printMaxOfMin(v, n);
}