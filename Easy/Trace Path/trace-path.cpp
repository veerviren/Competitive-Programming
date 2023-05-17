//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int col = 0, row = 0;
        int minn = 0, mxn = 0;
        int mim = 0, mxm = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'R')
            {
                col++;
                mxm = max(mxm, col);
            }
            else if(s[i] == 'L'){
                col--;
                mim = min(mim, col);
            }
            else if(s[i] == 'D')
            {
                row--;
                minn = min(minn, row);
            }
            else {
                row++;
                mxn = max(mxn, row);
            }
        }
        
        if(mxm - mim >= m || mxn - minn >= n)
        {
            return 0;
        }
        else{
            return 1;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends