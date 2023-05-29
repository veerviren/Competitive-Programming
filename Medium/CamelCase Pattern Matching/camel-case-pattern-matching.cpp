//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> d, string p) {
        // code here
        vector<string> ans;
        
        for(int i = 0; i < n; i++)
        {
            int st = 0;
            for(int j = 0; j < d[i].size(); j++)
            {
                // cout << d[i][j] << " " << p[st] << endl;
                if(d[i][j] >= 'A' and d[i][j] <= 'Z' )
                {
                    if(d[i][j] == p[st])
                        st++;
                    else break;
                }
                
            }
            
            // cout << st << endl;
            
            if(st == p.size())
            {
                ans.push_back(d[i]);
            }
        }
        
        if(ans.size() == 0)
        {
            return {"-1"};
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends