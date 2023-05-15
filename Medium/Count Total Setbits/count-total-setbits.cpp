//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long n) 
    {
        // code here
       if(n<=1) return n;
        long long x=log2(n);
        long long lp=pow(2,x);
        long long temp=n-pow(2,x);
        return ((lp*x)/2)+(n-lp+1)+countBits(temp);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends