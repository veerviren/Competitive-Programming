//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int m1 = 0, m2 = 0;
	    
	    for(int i = 0; i < n; i++)
	    {
	        m1 = max(m1, arr[i]);
	    }
	    
	    for(int i = 0; i < n; i++)
	    {
	        if(max(arr[i], m2) != m1)
	        {
	            m2 = max(arr[i], m2);
	        }
	    }
	    
	    if(m2 == 0)
	    {
	        return -1;
	    }
	    return m2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends