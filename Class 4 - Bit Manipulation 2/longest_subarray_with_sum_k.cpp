//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int lenOfLongSubarr(int a[], int n, int k)
    {
        map<int, int> mp;
        int j = 0;
        int sum = 0;
        int ans = 0;
        while (j < n)
        {
            sum += a[j];
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = j;
            }
            if (sum == k)
            {
                ans = max(ans, j + 1);
            }
            else if (mp.find(sum - k) != mp.end())
            {
                int i = mp[sum - k];
                ans = max(ans, j - i);
            }

            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    // code

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends