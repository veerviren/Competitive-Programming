#include <iostream>
using namespace std;

void solve(int n, string src, string dest, string tem1, string tem2)
{
    if(n == 0)
    {
        return;
    }
    if(n == 1)
    {
        cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;
        return;
    }
    solve(n - 2, src, tem1, tem2, dest);
    cout << "Transfer disk " << n - 1 << " from " << src << " to " << tem2 << endl;
    cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;
    cout << "Transfer disk " << n - 1 << " from " << tem2 << " to " << dest << endl;
    solve(n - 2, tem1, dest, src, tem2);
}

int main()
{
    int numOfDisks;
    cin >> numOfDisks;
    cout << "Instructions :-" << endl;
    cout << "Higher the number of disk, higher the size of the disk" << endl;
    solve(numOfDisks, "T1", "T4", "T2", "T3");

    return 0;
}